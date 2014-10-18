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

namespace jace {

UpdaterRunner::UpdaterRunner(const QString gamepackHash, const QString updaterServer)
    : QObject(), server(updaterServer), hash(gamepackHash) {
    connect(this, SIGNAL(started()),
            this, SLOT(downloadData()));
}

QString UpdaterRunner::getURL() const {
    QString url (server);
    return url.replace("{hash}", hash);
}

QByteArray UpdaterRunner::getData() {
    QMutexLocker locker (&dataMutex);
    return data;
}

void UpdaterRunner::start() {
    QMutexLocker locker (&dataMutex);

    if (data.isEmpty()) {
        // This signal is connected to the `downloadData()` slot,
        // So it will be called later.
        emit started();
    } else {
        // Else we emit the finished signal immediately.
        emit finished(hash, data);
    }

}

void UpdaterRunner::downloadData() {
    QMutexLocker locker (&dataMutex);
    emit error(hash, "UpdaterRunner::downloadData() - This function is not yet implemented");
}

} // namespace jace
