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
#------------------------------------------------------------------------

#------------------------------------------------
#
# .pro file for the Java bridge
#
# This module manages the connection with the
# running Java Virtual Machine and is therefore
# essential for starting Runescape. The Java bridge
# then acts as a gateway between the rest
# of PowerGrid and Runescape.
#
#------------------------------------------------

#------------------------------------------------
# The bridge only needs the QtCore, not the QtGUI.
#------------------------------------------------

QT = core

include (../cpp11enabler.pro) # enables C++11 and compiler-specific functionality

TARGET      = Javabridge
TEMPLATE    = lib
CONFIG     += static

# Temporary files are placed in the "tmp" folder
OBJECTS_DIR = tmp
MOC_DIR     = tmp

# this define is required to prevent the static VM loader
# from trying to bind to a statically linked jvm.lib
# We don't want this since we bind to the jvm library dynamically.
DEFINES    += JACE_WANT_DYNAMIC_LOAD

#------------------------------------------------
# All headers and source files to include
#------------------------------------------------

HEADERS += javaenvironment.h \
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
    jace/proxy/java/util/Collection.h
SOURCES += javaenvironment.cpp \
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

OTHER_FILES =

#------------------------------------------------
# Add the dependency for jni
#------------------------------------------------

# Set the base directory for the Java Native Interface libraries
JNI_BASE = $$PWD/../../External/JNI

# Find the appropriate OS name for the platform-dependent JNI include.
win32:      OS_NAME     = win32
else:macx:  OS_NAME     = darwin
else:unix:  OS_NAME     = unix
else:       error ("Unsupported OS")

JNI_HEADERS = $$JNI_BASE/include \
              $$JNI_BASE/include/$$OS_NAME

# On Mac OS, Java should be linked as a framework instead of a library.
# else (on windows and generic unix), the jvm is a normal (shared) library

macx:  LIBS += -framework JavaVM
else:  LIBS += -L$$JNI_BASE/lib -ljvm

INCLUDEPATH += $$JNI_HEADERS
DEPENDPATH  += $$JNI_HEADERS

#------------------------------------------------
# Add the dependency for JACE
#------------------------------------------------

JACE_BASE = $$PWD/../../External/JACE

INCLUDEPATH += $$JACE_BASE/include
DEPENDPATH  += $$JACE_BASE/include
LIBS += -L$$JACE_BASE/lib -ljace
