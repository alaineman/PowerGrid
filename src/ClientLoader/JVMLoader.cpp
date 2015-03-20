/**************************************************************************
** Copyright 2014 Patrick Kramer, Vincent Wassenaar
** This file is part of PowerGrid.
**
** PowerGrid is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** PowerGrid is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
**************************************************************************/

#include "JVMLoader.h"

#include "jace/JNIHelper.h"

Q_LOGGING_CATEGORY(vmLoader, "JVMLoader")

namespace jh = ::jace::helper;
using jace::LibraryPath;

namespace loader {

namespace {
    std::string getSystemLibraryPrefix() {
#ifdef Q_OS_WIN32
        QByteArray profile = qgetenv("USERPROFILE");
        QByteArray libPath = qgetenv("PATH");
        return std::string(libPath.constData()).append(";")
                   .append(profile.constData()).append("/");
#else
        QByteArray libPath = qgetenv("LD_LIBRARY_PATH");
        return std::string(libPath.constData()).append(":~/");
#endif
    }
}

void JVMLoader::setLibraryPath(const QString path) {
    LibraryPath lib(getSystemLibraryPrefix().append(qPrintable(path)).c_str());
    addOption(lib);
}

void JVMLoader::startJVM() {

}

}
