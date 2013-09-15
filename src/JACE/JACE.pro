#------------------------------------------------------------------------
# Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar
#
# This file is part of PowerGrid.
#
# PowerGrid is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# PowerGrid is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
#
# Note that the files contained in this project do NOT fall under the
# terms of the GNU General Public License, but instead fall under a
# different license as mentioned below. This file does fall under the
# GNU General Public License.
#------------------------------------------------------------------------

#------------------------------------------------------------------------
# All files in the "jace" subdirectory belong to JACE.
# JACE falls under the terms of the following license:
#
# Copyright (c) 2002, Toby Reyelts
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification,
# are permitted provided that the following conditions are met:
#
# Redistributions of source code must retain the above copyright notice,
# this list of conditions and the following disclaimer.
# Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following disclaimer in the documentation
# and/or other materials provided with the distribution.
# Neither the name of Toby Reyelts nor the names of his contributors
# may be used to endorse or promote products derived from this software
# without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
# GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#------------------------------------------------------------------------

#------------------------------------------------------------------------
# All other files are part of the Oracle JDK.
# These files are subject to the following license terms:
#
# Copyright (c) 1999, 2001, Oracle and/or its affiliates
# All rights reserved.
#
# They are modified for optimization within the context of the project
# and to enhance the clarity of these files
#------------------------------------------------------------------------

#------------------------------------------------------------------------
# .pro file for the JACE library.
# This subproject contains the functionality required to bridge the gap
# between Java and C++. The JACE library is used for that purpose.
# JACE has been optimized for use with PowerGrid and
#------------------------------------------------------------------------

TARGET      = JACE
TEMPLATE    = lib
CONFIG     += static # We tell QMake we're building a static lib
CONFIG     -= qt     # JACE has nothing to do with QT, so we remove it from the config

# JACE uses .tsd and .tsp files as C++ header files
QMAKE_EXT_H += .tsp .tsd

include (../global_def.pro)

#------------------------------------------------
# Add the dependency for jni
#------------------------------------------------
LIBS += -L$$PWD/../../lib -ljvm

# We include the JNI headers in the project directly, this also allows optimization of the JNI headers.
HEADERS += \
    jvmticmlr.h \
    jvmti.h \
    jni.h \
    jni_md.h \
    jdwpTransport.h \
    jawt.h \
    jawt_md.h \
    classfile_constants.h

win32 {
    DEFINES += JNI_WIN32
}
else:macx {
    DEFINES += JNI_MACX
}

#------------------------------------------------
# Files in this project. This contains all JACE
# classes as well as all generated proxy classes.
#------------------------------------------------

HEADERS    += \
    jace/WrapperVmLoader.h \
    jace/Win32VmLoader.h \
    jace/VmLoader.h \
    jace/UnixVmLoader.h \
    jace/StaticVmLoader.h \
    jace/Peer.h \
    jace/os_dep.h \
    jace/OptionList.h \
    jace/namespace.h \
    jace/JSignature.h \
    jace/JNIHelper.h \
    jace/JNIException.h \
    jace/JMethod.h \
    jace/JFieldProxyHelper.h \
    jace/JFieldProxy.h \
    jace/JFieldHelper.h \
    jace/JField.h \
    jace/JFactory.h \
    jace/JEnlister.h \
    jace/JConstructor.h \
    jace/JClassImpl.h \
    jace/JClass.h \
    jace/javacast.h \
    jace/JArrayHelper.h \
    jace/JArray.tsd \
    jace/JArray.h \
    jace/JArguments.h \
    jace/ElementProxyHelper.h \
    jace/ElementProxy.h \
    jace/counted_ptr.h \
    jace/BaseException.h \
    jace/proxy/JValue.h \
    jace/proxy/JObject.h \
    jace/proxy/types/JVoid.h \
    jace/proxy/types/JShort.h \
    jace/proxy/types/JLong.h \
    jace/proxy/types/JInt.h \
    jace/proxy/types/JFloat.h \
    jace/proxy/types/JDouble.h \
    jace/proxy/types/JChar.h \
    jace/proxy/types/JByte.h \
    jace/proxy/types/JBoolean.h \
    jace/JMethod.tsp \
    jace/JMethod.tsd \
    jace/JFieldProxy.tsp \
    jace/JFieldProxy.tsd \
    jace/JField.tsp \
    jace/JField.tsd \
    jace/javacast.tsp \
    jace/javacast.tsd \
    jace/JArray.tsp \
    jace/ElementProxy.tsp \
    jace/ElementProxy.tsd

SOURCES    += \
    jace/WrapperVmLoader.cpp \
    jace/Win32VmLoader.cpp \
    jace/VmLoader.cpp \
    jace/UnixVmLoader.cpp \
    jace/StaticVmLoader.cpp \
    jace/Peer.cpp \
    jace/os_dep.cpp \
    jace/OptionList.cpp \
    jace/JSignature.cpp \
    jace/JNIHelper.cpp \
    jace/JNIException.cpp \
    jace/JMethod.cpp \
    jace/JFieldProxyHelper.cpp \
    jace/JFieldProxy.cpp \
    jace/JFieldHelper.cpp \
    jace/JField.cpp \
    jace/JFactory.cpp \
    jace/JEnlister.cpp \
    jace/JConstructor.cpp \
    jace/JClassImpl.cpp \
    jace/JClass.cpp \
    jace/javacast.cpp \
    jace/JArrayHelper.cpp \
    jace/JArray.cpp \
    jace/JArguments.cpp \
    jace/ElementProxyHelper.cpp \
    jace/ElementProxy.cpp \
    jace/BaseException.cpp \
    jace/proxy/JValue.cpp \
    jace/proxy/JObject.cpp \
    jace/proxy/types/JVoid.cpp \
    jace/proxy/types/JShort.cpp \
    jace/proxy/types/JLong.cpp \
    jace/proxy/types/JInt.cpp \
    jace/proxy/types/JFloat.cpp \
    jace/proxy/types/JDouble.cpp \
    jace/proxy/types/JChar.cpp \
    jace/proxy/types/JByte.cpp \
    jace/proxy/types/JBoolean.cpp \
