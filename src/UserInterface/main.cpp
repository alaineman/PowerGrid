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

#include "main.h"
using namespace std;

#include "jace/UpdaterRunner.h"
#include "jace/RSClassMapper.h"
using namespace jace;

#include "net/pgrid/loader/pgloader.h"
using net::pgrid::loader::PGLoader;

int main(int argc, char** argv) {
    initializeLoggers();

    try {
        startJavaClient();
    } catch (JNIException& e) {
        qCWarning(logLauncher) << "Error starting Java client:" << e.what();
        return EXIT_FAILURE;
    }

    qCDebug(logLauncher) << "JVM started, creating control panel";
    QApplication app (argc, argv);
    app.setApplicationName(PG_NAME_STR);
    app.setApplicationVersion(PG_VERSION_STR);

    MainWindow window;
    window.show();
    window.setJVMVersion(helper::getJavaProperty("java.version"));

    runUpdater();
    qCDebug(logLauncher) << "Startup completed";
    return app.exec();
}

void PGMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg) {
    // We prefer to label the message with its category. However, if no category is defined,
    // we use a prefix based on the message type (debug, warning, critical, or fatal).
    const char* prefix = context.category;

    if (!strcmp(prefix, "default")) {
        switch (type) {
        case QtDebugMsg:
            cout << "INFORMATION  | ";
            break;
        case QtWarningMsg:
            cout << "WARNING      | ";
            break;
        case QtCriticalMsg:
            cout << "CRITICAL     | ";
            break;
        case QtFatalMsg:
            cout << "FATAL ERROR  | ";
        }
    } else {
        // Print the prefix and pad it to a length of (at least) 13.
        cout << prefix;
        int len = strlen(prefix);
        while (len < 13) {
            cout << ' ';
            len++;
        }
        cout << "| ";
    }
    // After the label we print the message, split into lines.
    QStringList lines = msg.split(QRegExp("\r?\n"));
    cout << qPrintable(lines.first()) << endl;
    int pos = 1;
    while (pos < lines.size()) {
        // Don't repeat the label for consecutive lines
        cout << "             | " << qPrintable(lines.at(pos)) << endl;
    }
#if defined(PG_DEBUG) && !defined(PG_DEBUG_NO_TRACE)
    // We print the origin of the message in debug builds
    // (unless this was specifically disabled with PG_DEBUG_NO_TRACE)
    cout << "             | (logged from " << context.file << ": " << context.line << ")" << endl;
#else
    Q_UNUSED(context)
#endif
}

void initializeLoggers() {
#ifdef PG_DEBUG
    QLoggingCategory::setFilterRules(QStringLiteral("*.debug=true"));
    QLoggingCategory::setFilterRules(QStringLiteral("qt.*.debug=false"));
#endif
    qInstallMessageHandler(PGMessageHandler);
}

void startJavaClient() throw (JNIException) {
    qCDebug(logLauncher) << "Attempting to load JVM...";

    JavaLoader loader;
    loader.setLibraryPath("jagexcache/runescape/LIVE");

    loader.addOption( ClassPath("PowerGridLoader.jar") );
    loader.addOption( JavaAgent("PowerGridLoader.jar") );
    loader.addOption( CustomOption("-Xss2M") );
#ifdef PG_DEBUG
    // check JNI calls in debug mode
    loader.addOption( CustomOption("-Xcheck:jni") );
#endif
    loader.startJVM();

    // "-i": Intercept output from System.out / System.err
    // "-e": Allow Exceptions to propagate into the native client (so we can catch them here and exit gracefully).
    PGLoader::start({"-i", "-e"});
}

void runUpdater() {
    qCDebug(logLauncher) << "Retrieving updater data";
    // Contact the updater server to collect the updater data.
    jint hash = PGLoader::computeClientHash();
    UpdaterRunner runner (QString::number(hash));
    RSClassMapper* mapper = RSClassMapper::DefaultInstance();
    runner.connect(&runner, SIGNAL(finished(QString, QByteArray)),
                   mapper,  SLOT  (parseData(QString, QByteArray)));
    runner.connect(&runner, SIGNAL(error(QString, QString)),
                   mapper,  SLOT  (dataFailed(QString, QString)));
    runner.start();
}

Q_LOGGING_CATEGORY(logLauncher, "LAUNCHER")

