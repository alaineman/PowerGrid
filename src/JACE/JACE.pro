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
#------------------------------------------------------------------------

#------------------------------------------------------------------------
# .pro file for the JACE library.
# This subproject contains the functionality required to bridge the gap
# between Java and C++. The JACE library is used for that purpose.
# JACE has been optimized for use with PowerGrid and
#------------------------------------------------------------------------

# We build JACE as a DLL, this splits the Java-bridging part from the rest of
# PowerGrid. It also stores all proxy classes together, but separate from the
# rest of the project.
TARGET      = JACE
TEMPLATE    = lib
CONFIG     += thread    # We tell QMake we're building a multi-threaded dll  (required for JACE)
CONFIG     -= qt            # JACE has nothing to do with QT, so we remove it from the config

# JACE generated proxy classes may produce various compiler warnings.
# Since these are not interesting to us, we tell QMake to suppress
# these warnings.
CONFIG     += warn_off

OBJECTS_DIR = tmp
MOC_DIR     = tmp

QMAKE_CXXFLAGS += -fpic # Generate Position Independant Code for use in shared library

DEFINES    += JACE_EXPORTS JACE_PROXY_EXPORTS # Needed to configure JACE for exporting dll symbols.

#------------------------------------------------
# Add the dependency for jni
#------------------------------------------------

# On Mac OS, Java should be linked as a framework instead of a library.
# else (on windows and generic unix), the jvm is a normal (shared) library
macx:  LIBS += -framework JavaVM
else:  LIBS += -L$$PWD/../../lib -ljvm

# QMake cannot find jni.h for some reason. As such, we include it in the project directly.
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
    # The win32 specific headers also include these headers for some reason.
    # However, they do not appear to be used. As such, they may be removed later.
    HEADERS += \
        bridge/AccessBridgeCallbacks.h \
        bridge/AccessBridgeCalls.h \
        bridge/AccessBridgePackages.h
    SOURCES += \
        bridge/AccessBridgeCalls.c
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
    jace/proxy/java/io/Writer.h \
    jace/proxy/java/io/UnsupportedEncodingException.h \
    jace/proxy/java/io/SyncFailedException.h \
    jace/proxy/java/io/Serializable.h \
    jace/proxy/java/io/Reader.h \
    jace/proxy/java/io/PrintWriter.h \
    jace/proxy/java/io/PrintStream.h \
    jace/proxy/java/io/OutputStream.h \
    jace/proxy/java/io/IOException.h \
    jace/proxy/java/io/InputStream.h \
    jace/proxy/java/io/Flushable.h \
    jace/proxy/java/io/FilterOutputStream.h \
    jace/proxy/java/io/FileNotFoundException.h \
    jace/proxy/java/io/FilenameFilter.h \
    jace/proxy/java/io/FileFilter.h \
    jace/proxy/java/io/FileDescriptor.h \
    jace/proxy/java/io/File.h \
    jace/proxy/java/io/Console.h \
    jace/proxy/java/io/Closeable.h \
    jace/proxy/java/lang/annotation/Annotation.h \
    jace/proxy/java/lang/reflect/TypeVariable.h \
    jace/proxy/java/lang/reflect/Type.h \
    jace/proxy/java/lang/reflect/Method.h \
    jace/proxy/java/lang/reflect/Member.h \
    jace/proxy/java/lang/reflect/InvocationTargetException.h \
    jace/proxy/java/lang/reflect/GenericDeclaration.h \
    jace/proxy/java/lang/reflect/Field.h \
    jace/proxy/java/lang/reflect/Constructor.h \
    jace/proxy/java/lang/reflect/AnnotatedElement.h \
    jace/proxy/java/lang/reflect/AccessibleObject.h \
    jace/proxy/java/lang/Throwable.h \
    jace/proxy/java/lang/ThreadGroup.h \
    jace/proxy/java/lang/Thread.UncaughtExceptionHandler.h \
    jace/proxy/java/lang/Thread.State.h \
    jace/proxy/java/lang/Thread.h \
    jace/proxy/java/lang/System.h \
    jace/proxy/java/lang/StringBuilder.h \
    jace/proxy/java/lang/StringBuffer.h \
    jace/proxy/java/lang/String.h \
    jace/proxy/java/lang/StackTraceElement.h \
    jace/proxy/java/lang/SecurityManager.h \
    jace/proxy/java/lang/SecurityException.h \
    jace/proxy/java/lang/RuntimeException.h \
    jace/proxy/java/lang/Runnable.h \
    jace/proxy/java/lang/ReflectiveOperationException.h \
    jace/proxy/java/lang/Readable.h \
    jace/proxy/java/lang/Package.h \
    jace/proxy/java/lang/Object.h \
    jace/proxy/java/lang/NumberFormatException.h \
    jace/proxy/java/lang/NoSuchMethodException.h \
    jace/proxy/java/lang/NoSuchFieldException.h \
    jace/proxy/java/lang/Iterable.h \
    jace/proxy/java/lang/InterruptedException.h \
    jace/proxy/java/lang/InstantiationException.h \
    jace/proxy/java/lang/IllegalArgumentException.h \
    jace/proxy/java/lang/IllegalAccessException.h \
    jace/proxy/java/lang/Exception.h \
    jace/proxy/java/lang/Enum.h \
    jace/proxy/java/lang/Comparable.h \
    jace/proxy/java/lang/Cloneable.h \
    jace/proxy/java/lang/ClassNotFoundException.h \
    jace/proxy/java/lang/ClassLoader.h \
    jace/proxy/java/lang/Class.h \
    jace/proxy/java/lang/CharSequence.h \
    jace/proxy/java/lang/AutoCloseable.h \
    jace/proxy/java/lang/Appendable.h \
    jace/proxy/java/lang/AbstractStringBuilder.h \
    jace/proxy/java/net/URLStreamHandlerFactory.h \
    jace/proxy/java/net/URLStreamHandler.h \
    jace/proxy/java/net/URLConnection.h \
    jace/proxy/java/net/URL.h \
    jace/proxy/java/net/URISyntaxException.h \
    jace/proxy/java/net/URI.h \
    jace/proxy/java/net/UnknownHostException.h \
    jace/proxy/java/net/SocketException.h \
    jace/proxy/java/net/SocketAddress.h \
    jace/proxy/java/net/Proxy.Type.h \
    jace/proxy/java/net/Proxy.h \
    jace/proxy/java/net/NetworkInterface.h \
    jace/proxy/java/net/MalformedURLException.h \
    jace/proxy/java/net/InetAddress.h \
    jace/proxy/java/net/FileNameMap.h \
    jace/proxy/java/net/ContentHandlerFactory.h \
    jace/proxy/java/net/ContentHandler.h \
    jace/proxy/java/nio/channels/spi/AbstractInterruptibleChannel.h \
    jace/proxy/java/nio/channels/WritableByteChannel.h \
    jace/proxy/java/nio/channels/SeekableByteChannel.h \
    jace/proxy/java/nio/channels/ScatteringByteChannel.h \
    jace/proxy/java/nio/channels/ReadableByteChannel.h \
    jace/proxy/java/nio/channels/InterruptibleChannel.h \
    jace/proxy/java/nio/channels/GatheringByteChannel.h \
    jace/proxy/java/nio/channels/FileLock.h \
    jace/proxy/java/nio/channels/FileChannel.MapMode.h \
    jace/proxy/java/nio/channels/FileChannel.h \
    jace/proxy/java/nio/channels/CompletionHandler.h \
    jace/proxy/java/nio/channels/Channel.h \
    jace/proxy/java/nio/channels/ByteChannel.h \
    jace/proxy/java/nio/channels/AsynchronousFileChannel.h \
    jace/proxy/java/nio/channels/AsynchronousChannel.h \
    jace/proxy/java/nio/charset/CodingErrorAction.h \
    jace/proxy/java/nio/charset/CoderResult.h \
    jace/proxy/java/nio/charset/CharsetEncoder.h \
    jace/proxy/java/nio/charset/CharsetDecoder.h \
    jace/proxy/java/nio/charset/Charset.h \
    jace/proxy/java/nio/charset/CharacterCodingException.h \
    jace/proxy/java/nio/file/attribute/UserPrincipalLookupService.h \
    jace/proxy/java/nio/file/attribute/UserPrincipal.h \
    jace/proxy/java/nio/file/attribute/GroupPrincipal.h \
    jace/proxy/java/nio/file/attribute/FileTime.h \
    jace/proxy/java/nio/file/attribute/FileStoreAttributeView.h \
    jace/proxy/java/nio/file/attribute/FileAttributeView.h \
    jace/proxy/java/nio/file/attribute/FileAttribute.h \
    jace/proxy/java/nio/file/attribute/BasicFileAttributes.h \
    jace/proxy/java/nio/file/attribute/AttributeView.h \
    jace/proxy/java/nio/file/spi/FileSystemProvider.h \
    jace/proxy/java/nio/file/WatchService.h \
    jace/proxy/java/nio/file/WatchKey.h \
    jace/proxy/java/nio/file/WatchEvent.Modifier.h \
    jace/proxy/java/nio/file/WatchEvent.Kind.h \
    jace/proxy/java/nio/file/Watchable.h \
    jace/proxy/java/nio/file/PathMatcher.h \
    jace/proxy/java/nio/file/Path.h \
    jace/proxy/java/nio/file/OpenOption.h \
    jace/proxy/java/nio/file/LinkOption.h \
    jace/proxy/java/nio/file/FileSystem.h \
    jace/proxy/java/nio/file/FileStore.h \
    jace/proxy/java/nio/file/DirectoryStream.h \
    jace/proxy/java/nio/file/DirectoryStream.Filter.h \
    jace/proxy/java/nio/file/CopyOption.h \
    jace/proxy/java/nio/file/AccessMode.h \
    jace/proxy/java/nio/ShortBuffer.h \
    jace/proxy/java/nio/MappedByteBuffer.h \
    jace/proxy/java/nio/LongBuffer.h \
    jace/proxy/java/nio/IntBuffer.h \
    jace/proxy/java/nio/FloatBuffer.h \
    jace/proxy/java/nio/DoubleBuffer.h \
    jace/proxy/java/nio/CharBuffer.h \
    jace/proxy/java/nio/ByteOrder.h \
    jace/proxy/java/nio/ByteBuffer.h \
    jace/proxy/java/nio/Buffer.h \
    jace/proxy/java/security/cert/CertPath.h \
    jace/proxy/java/security/cert/CertificateException.h \
    jace/proxy/java/security/cert/CertificateEncodingException.h \
    jace/proxy/java/security/cert/Certificate.h \
    jace/proxy/java/security/Timestamp.h \
    jace/proxy/java/security/SignatureException.h \
    jace/proxy/java/security/PublicKey.h \
    jace/proxy/java/security/ProtectionDomain.h \
    jace/proxy/java/security/Principal.h \
    jace/proxy/java/security/PermissionCollection.h \
    jace/proxy/java/security/Permission.h \
    jace/proxy/java/security/NoSuchProviderException.h \
    jace/proxy/java/security/NoSuchAlgorithmException.h \
    jace/proxy/java/security/KeyException.h \
    jace/proxy/java/security/Key.h \
    jace/proxy/java/security/InvalidKeyException.h \
    jace/proxy/java/security/Guard.h \
    jace/proxy/java/security/GeneralSecurityException.h \
    jace/proxy/java/security/CodeSource.h \
    jace/proxy/java/security/CodeSigner.h \
    jace/proxy/java/util/concurrent/TimeUnit.h \
    jace/proxy/java/util/concurrent/TimeoutException.h \
    jace/proxy/java/util/concurrent/Future.h \
    jace/proxy/java/util/concurrent/ExecutorService.h \
    jace/proxy/java/util/concurrent/Executor.h \
    jace/proxy/java/util/concurrent/ExecutionException.h \
    jace/proxy/java/util/concurrent/Callable.h \
    jace/proxy/java/util/SortedMap.h \
    jace/proxy/java/util/Set.h \
    jace/proxy/java/util/Properties.h \
    jace/proxy/java/util/MissingResourceException.h \
    jace/proxy/java/util/Map.h \
    jace/proxy/java/util/Locale.h \
    jace/proxy/java/util/Locale.Category.h \
    jace/proxy/java/util/ListIterator.h \
    jace/proxy/java/util/List.h \
    jace/proxy/java/util/Iterator.h \
    jace/proxy/java/util/InvalidPropertiesFormatException.h \
    jace/proxy/java/util/Hashtable.h \
    jace/proxy/java/util/Enumeration.h \
    jace/proxy/java/util/Dictionary.h \
    jace/proxy/java/util/Date.h \
    jace/proxy/java/util/Comparator.h \
    jace/proxy/java/util/Collection.h \
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
    jace/proxy/java/io/Writer.cpp \
    jace/proxy/java/io/UnsupportedEncodingException.cpp \
    jace/proxy/java/io/SyncFailedException.cpp \
    jace/proxy/java/io/Serializable.cpp \
    jace/proxy/java/io/Reader.cpp \
    jace/proxy/java/io/PrintWriter.cpp \
    jace/proxy/java/io/PrintStream.cpp \
    jace/proxy/java/io/OutputStream.cpp \
    jace/proxy/java/io/IOException.cpp \
    jace/proxy/java/io/InputStream.cpp \
    jace/proxy/java/io/Flushable.cpp \
    jace/proxy/java/io/FilterOutputStream.cpp \
    jace/proxy/java/io/FileNotFoundException.cpp \
    jace/proxy/java/io/FilenameFilter.cpp \
    jace/proxy/java/io/FileFilter.cpp \
    jace/proxy/java/io/FileDescriptor.cpp \
    jace/proxy/java/io/File.cpp \
    jace/proxy/java/io/Console.cpp \
    jace/proxy/java/io/Closeable.cpp \
    jace/proxy/java/lang/annotation/Annotation.cpp \
    jace/proxy/java/lang/reflect/TypeVariable.cpp \
    jace/proxy/java/lang/reflect/Type.cpp \
    jace/proxy/java/lang/reflect/Method.cpp \
    jace/proxy/java/lang/reflect/Member.cpp \
    jace/proxy/java/lang/reflect/InvocationTargetException.cpp \
    jace/proxy/java/lang/reflect/GenericDeclaration.cpp \
    jace/proxy/java/lang/reflect/Field.cpp \
    jace/proxy/java/lang/reflect/Constructor.cpp \
    jace/proxy/java/lang/reflect/AnnotatedElement.cpp \
    jace/proxy/java/lang/reflect/AccessibleObject.cpp \
    jace/proxy/java/lang/Throwable.cpp \
    jace/proxy/java/lang/ThreadGroup.cpp \
    jace/proxy/java/lang/Thread.UncaughtExceptionHandler.cpp \
    jace/proxy/java/lang/Thread.State.cpp \
    jace/proxy/java/lang/Thread.cpp \
    jace/proxy/java/lang/System.cpp \
    jace/proxy/java/lang/StringBuilder.cpp \
    jace/proxy/java/lang/StringBuffer.cpp \
    jace/proxy/java/lang/String.cpp \
    jace/proxy/java/lang/StackTraceElement.cpp \
    jace/proxy/java/lang/SecurityManager.cpp \
    jace/proxy/java/lang/SecurityException.cpp \
    jace/proxy/java/lang/RuntimeException.cpp \
    jace/proxy/java/lang/Runnable.cpp \
    jace/proxy/java/lang/ReflectiveOperationException.cpp \
    jace/proxy/java/lang/Readable.cpp \
    jace/proxy/java/lang/Package.cpp \
    jace/proxy/java/lang/Object.cpp \
    jace/proxy/java/lang/NumberFormatException.cpp \
    jace/proxy/java/lang/NoSuchMethodException.cpp \
    jace/proxy/java/lang/NoSuchFieldException.cpp \
    jace/proxy/java/lang/Iterable.cpp \
    jace/proxy/java/lang/InterruptedException.cpp \
    jace/proxy/java/lang/InstantiationException.cpp \
    jace/proxy/java/lang/IllegalArgumentException.cpp \
    jace/proxy/java/lang/IllegalAccessException.cpp \
    jace/proxy/java/lang/Exception.cpp \
    jace/proxy/java/lang/Enum.cpp \
    jace/proxy/java/lang/Comparable.cpp \
    jace/proxy/java/lang/Cloneable.cpp \
    jace/proxy/java/lang/ClassNotFoundException.cpp \
    jace/proxy/java/lang/ClassLoader.cpp \
    jace/proxy/java/lang/Class.cpp \
    jace/proxy/java/lang/CharSequence.cpp \
    jace/proxy/java/lang/AutoCloseable.cpp \
    jace/proxy/java/lang/Appendable.cpp \
    jace/proxy/java/lang/AbstractStringBuilder.cpp \
    jace/proxy/java/net/URLStreamHandlerFactory.cpp \
    jace/proxy/java/net/URLStreamHandler.cpp \
    jace/proxy/java/net/URLConnection.cpp \
    jace/proxy/java/net/URL.cpp \
    jace/proxy/java/net/URISyntaxException.cpp \
    jace/proxy/java/net/URI.cpp \
    jace/proxy/java/net/UnknownHostException.cpp \
    jace/proxy/java/net/SocketException.cpp \
    jace/proxy/java/net/SocketAddress.cpp \
    jace/proxy/java/net/Proxy.Type.cpp \
    jace/proxy/java/net/Proxy.cpp \
    jace/proxy/java/net/NetworkInterface.cpp \
    jace/proxy/java/net/MalformedURLException.cpp \
    jace/proxy/java/net/InetAddress.cpp \
    jace/proxy/java/net/FileNameMap.cpp \
    jace/proxy/java/net/ContentHandlerFactory.cpp \
    jace/proxy/java/net/ContentHandler.cpp \
    jace/proxy/java/nio/channels/spi/AbstractInterruptibleChannel.cpp \
    jace/proxy/java/nio/channels/WritableByteChannel.cpp \
    jace/proxy/java/nio/channels/SeekableByteChannel.cpp \
    jace/proxy/java/nio/channels/ScatteringByteChannel.cpp \
    jace/proxy/java/nio/channels/ReadableByteChannel.cpp \
    jace/proxy/java/nio/channels/InterruptibleChannel.cpp \
    jace/proxy/java/nio/channels/GatheringByteChannel.cpp \
    jace/proxy/java/nio/channels/FileLock.cpp \
    jace/proxy/java/nio/channels/FileChannel.MapMode.cpp \
    jace/proxy/java/nio/channels/FileChannel.cpp \
    jace/proxy/java/nio/channels/CompletionHandler.cpp \
    jace/proxy/java/nio/channels/Channel.cpp \
    jace/proxy/java/nio/channels/ByteChannel.cpp \
    jace/proxy/java/nio/channels/AsynchronousFileChannel.cpp \
    jace/proxy/java/nio/channels/AsynchronousChannel.cpp \
    jace/proxy/java/nio/charset/CodingErrorAction.cpp \
    jace/proxy/java/nio/charset/CoderResult.cpp \
    jace/proxy/java/nio/charset/CharsetEncoder.cpp \
    jace/proxy/java/nio/charset/CharsetDecoder.cpp \
    jace/proxy/java/nio/charset/Charset.cpp \
    jace/proxy/java/nio/charset/CharacterCodingException.cpp \
    jace/proxy/java/nio/file/attribute/UserPrincipalLookupService.cpp \
    jace/proxy/java/nio/file/attribute/UserPrincipal.cpp \
    jace/proxy/java/nio/file/attribute/GroupPrincipal.cpp \
    jace/proxy/java/nio/file/attribute/FileTime.cpp \
    jace/proxy/java/nio/file/attribute/FileStoreAttributeView.cpp \
    jace/proxy/java/nio/file/attribute/FileAttributeView.cpp \
    jace/proxy/java/nio/file/attribute/FileAttribute.cpp \
    jace/proxy/java/nio/file/attribute/BasicFileAttributes.cpp \
    jace/proxy/java/nio/file/attribute/AttributeView.cpp \
    jace/proxy/java/nio/file/spi/FileSystemProvider.cpp \
    jace/proxy/java/nio/file/WatchService.cpp \
    jace/proxy/java/nio/file/WatchKey.cpp \
    jace/proxy/java/nio/file/WatchEvent.Modifier.cpp \
    jace/proxy/java/nio/file/WatchEvent.Kind.cpp \
    jace/proxy/java/nio/file/Watchable.cpp \
    jace/proxy/java/nio/file/PathMatcher.cpp \
    jace/proxy/java/nio/file/Path.cpp \
    jace/proxy/java/nio/file/OpenOption.cpp \
    jace/proxy/java/nio/file/LinkOption.cpp \
    jace/proxy/java/nio/file/FileSystem.cpp \
    jace/proxy/java/nio/file/FileStore.cpp \
    jace/proxy/java/nio/file/DirectoryStream.Filter.cpp \
    jace/proxy/java/nio/file/DirectoryStream.cpp \
    jace/proxy/java/nio/file/CopyOption.cpp \
    jace/proxy/java/nio/file/AccessMode.cpp \
    jace/proxy/java/nio/ShortBuffer.cpp \
    jace/proxy/java/nio/MappedByteBuffer.cpp \
    jace/proxy/java/nio/LongBuffer.cpp \
    jace/proxy/java/nio/IntBuffer.cpp \
    jace/proxy/java/nio/FloatBuffer.cpp \
    jace/proxy/java/nio/DoubleBuffer.cpp \
    jace/proxy/java/nio/CharBuffer.cpp \
    jace/proxy/java/nio/ByteOrder.cpp \
    jace/proxy/java/nio/ByteBuffer.cpp \
    jace/proxy/java/nio/Buffer.cpp \
    jace/proxy/java/security/cert/CertPath.cpp \
    jace/proxy/java/security/cert/CertificateException.cpp \
    jace/proxy/java/security/cert/CertificateEncodingException.cpp \
    jace/proxy/java/security/cert/Certificate.cpp \
    jace/proxy/java/security/Timestamp.cpp \
    jace/proxy/java/security/SignatureException.cpp \
    jace/proxy/java/security/PublicKey.cpp \
    jace/proxy/java/security/ProtectionDomain.cpp \
    jace/proxy/java/security/Principal.cpp \
    jace/proxy/java/security/PermissionCollection.cpp \
    jace/proxy/java/security/Permission.cpp \
    jace/proxy/java/security/NoSuchProviderException.cpp \
    jace/proxy/java/security/NoSuchAlgorithmException.cpp \
    jace/proxy/java/security/KeyException.cpp \
    jace/proxy/java/security/Key.cpp \
    jace/proxy/java/security/InvalidKeyException.cpp \
    jace/proxy/java/security/Guard.cpp \
    jace/proxy/java/security/GeneralSecurityException.cpp \
    jace/proxy/java/security/CodeSource.cpp \
    jace/proxy/java/security/CodeSigner.cpp \
    jace/proxy/java/util/concurrent/TimeUnit.cpp \
    jace/proxy/java/util/concurrent/TimeoutException.cpp \
    jace/proxy/java/util/concurrent/Future.cpp \
    jace/proxy/java/util/concurrent/ExecutorService.cpp \
    jace/proxy/java/util/concurrent/Executor.cpp \
    jace/proxy/java/util/concurrent/ExecutionException.cpp \
    jace/proxy/java/util/concurrent/Callable.cpp \
    jace/proxy/java/util/SortedMap.cpp \
    jace/proxy/java/util/Set.cpp \
    jace/proxy/java/util/Properties.cpp \
    jace/proxy/java/util/MissingResourceException.cpp \
    jace/proxy/java/util/Map.cpp \
    jace/proxy/java/util/Locale.cpp \
    jace/proxy/java/util/Locale.Category.cpp \
    jace/proxy/java/util/ListIterator.cpp \
    jace/proxy/java/util/List.cpp \
    jace/proxy/java/util/Iterator.cpp \
    jace/proxy/java/util/InvalidPropertiesFormatException.cpp \
    jace/proxy/java/util/Hashtable.cpp \
    jace/proxy/java/util/Enumeration.cpp \
    jace/proxy/java/util/Dictionary.cpp \
    jace/proxy/java/util/Date.cpp \
    jace/proxy/java/util/Comparator.cpp \
    jace/proxy/java/util/Collection.cpp
