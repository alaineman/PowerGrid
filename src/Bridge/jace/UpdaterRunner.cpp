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

#include "UpdaterRunner.h"

#include <QUrl>
#include <QNetworkRequest>

namespace jace {

UpdaterRunner::UpdaterRunner(const QString gamepackHash, const QString updaterServer)
    : QObject(), server(updaterServer), hash(gamepackHash), manager(NULL) {
}

QString UpdaterRunner::getURL() const {
    QString url (server);
    return url.replace("{hash}", hash);
}

QByteArray UpdaterRunner::getData() {
    return data;
}

void UpdaterRunner::start() {
    if (data.isEmpty()) {
        // The manager is connected to the `downloadData()` slot,
        // So it will be called later. Giving it 'this' as parent ensures
        // it's cleaned up when this UpdaterRunner is deleted.
        manager = new QNetworkAccessManager(this);
        connect(manager, SIGNAL(finished(QNetworkReply*)),
                this,    SLOT(processData(QNetworkReply*)));
        // Let the manager retrieve the URL contents asynchronously.
        manager->get(QNetworkRequest(QUrl(getURL())));
    } else {
        // Else we emit the finished signal immediately.
        emit finished(hash, data);
    }

}

void UpdaterRunner::processData(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        // Something went wrong, report error and stop.
        reportError(reply);
        return;
    }

    data = reply->readAll();
    manager->deleteLater();
    manager = NULL;
    reply->deleteLater();
    emit finished(hash, data);
}

void UpdaterRunner::reportError(QNetworkReply *reply) {
    QString msg = reply->errorString();
    manager->deleteLater();
    manager = NULL;
    reply->deleteLater();
    emit error(hash, msg);
}

} // namespace jace
