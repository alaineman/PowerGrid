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

#ifndef JVMLOADER_H
#define JVMLOADER_H

#include <QObject>

#include "jace/VmLoader.h"
#include "jace/OptionList.h"
#include "jace/JNIException.h"

#include "jace/Win32VmLoader.h"
#include "jace/macvmloader.h"
#include "jace/UnixVmLoader.h"

namespace loader {

using jace::Option;
using jace::OptionList;
class JVMLoader : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(JVMLoader)
private:
#ifdef Q_OS_WIN
    typedef jace::Win32VmLoader JavaPlatformLoader;
#elif defined(Q_OS_MACX)
    typedef jace::MacVmLoader JavaPlatformLoader;
#else
    typedef jace::UnixVmLoader JavaPlatformLoader;
#endif
    JavaPlatformLoader loader;
    OptionList options;
public:
    explicit JVMLoader(QObject *parent = 0) : QObject(parent) {}
    ~JVMLoader() {}
signals:
    void finished();
    void error(QString message);
public slots:
    void addOption(const Option& opt) { options.push_back(opt); }
    void setLibraryPath(const QString path);
    void startJVM();
};

}

#endif // JVMLOADER_H
