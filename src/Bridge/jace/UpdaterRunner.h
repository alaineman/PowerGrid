/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UPDATER_RUNNER_H
#define UPDATER_RUNNER_H

#include <QObject>
#include <QMutex>

#include <QNetworkAccessManager>
#include <QNetworkReply>

#define PG_DEFAULT_UPDATER_SERVER \
    QStringLiteral("http://pgrid.net/marneus/reflection_cache_{hash}.xml")

namespace jace {

/**
 * @brief Retrieves Updater data from the updater server
 *
 * This class retrieves updater data from the updater server.
 * The updater data can then be passed into an RSClassMapper
 * instance to provide a class/field mapping.
 *
 * Functions in this class are Thread-safe (all functions that
 * deal with mutable fields are synchronized on a single QMutex).
 *
 * @author Patrick Kramer
 */
class UpdaterRunner : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(UpdaterRunner)
private:
    QByteArray data;
    const QString server;
    const QString hash;
    QMutex dataMutex;
    QNetworkAccessManager *manager;
public:
    /**
     * @brief Creates a new UpdaterRunner instance.
     *
     * If the updaterServer is not specified, the default updater server
     * will be used (which is equal to @c PG_DEFAULT_UPDATER_SERVER).
     *
     * @param gamepackHash  - The hash of the gamepack to retrieve
     * @param updaterServer - The updater server to use.
     */
    explicit UpdaterRunner(const QString gamepackHash,
                           const QString updaterServer = PG_DEFAULT_UPDATER_SERVER);

    /**
     * @brief The URL to the updater server this UpdaterRunner uses.
     * @return the updater server link
     */
    QString getServer() const { return server; }
    /**
     * @brief The hash code of the gamepack to retrieve.
     * @return the hash code of the gamepack
     */
    QString getHash() const { return hash; }

    /**
     * @brief The URL for the updater data.
     *
     * This value is created by substituting "{hash}" in the server URL with
     * the actual hash code provided to this UpdaterRunner.
     *
     * @return the URL for the updater data
     */
    QString getURL() const;

    /**
     * @brief The updater data.
     *
     * If the data is not yet loaded, this function returns an empty
     * QByteArray. Otherwise, this function returns a QByteArray with
     * the loaded data. This function may block while the UpdaterRunner
     * is still loading the data.
     *
     * @return the updater data, or an empty QByteArray if the data
     *         is not loaded.
     */
    QByteArray getData();

public slots:
    /**
     * @brief Starts retrieving the data for the updater server.
     *
     * When the UpdaterRunner is done, the @c finished(QString,QByteArray)
     * signal will be emitted. When an error occurs, the
     * @c error(QString,QString) signal will be emitted instead.
     */
    void start();

private slots:
    /**
     * @brief Processes the updater data.
     *
     * This slot is called automatically when the network request succeeded.
     *
     * @param reply - The QNetworkReply with the updater data.
     */
    void processData(QNetworkReply *reply);

    /**
     * @brief Reports the given error.
     *
     * This slot is called automatically when the network request failed.
     * This slot translates the NetworkError to an error message and reports
     * it by emitting the @c error(QString, QString) signal.
     *
     * @param err - The error that caused the request to fail.
     */
    void reportError(const QNetworkReply *reply);

signals:
    /**
     * @brief Signal emitted when downloading the data has started.
     *
     * If the start() slot is called, but the data is already
     * available, this signal will not be emitted, but the signal
     * finished(QString,QByteArray) will be emitted immediately.
     * This signal will be emitted only when actual downloading
     * takes place.
     */
    void started();

    /**
     * @brief Signal emitted when the UpdaterRunner is finished.
     *
     * @param gamepackHash - the hash of the gamepack for which
     *                       the data is retrieved
     * @param updaterData  - the data that is retrieved by this
     *                       UpdaterRunner.
     */
    void finished(QString gamepackHash, QByteArray updaterData);

    /**
     * @brief Signal emitted when the UpdaterRunner failed to finish.
     *
     * @param gamepackHash - the hash of the gamepack for which
     *                       retrieving the data failed.
     * @param message      - a QString describing the error.
     */
    void error(QString gamepackHash, QString message);

};

}
#endif
