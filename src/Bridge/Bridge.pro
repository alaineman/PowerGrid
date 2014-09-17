#------------------------------------------------------------------------
# Copyright 2014 Patrick Kramer, Vincent Wassenaar
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
# different license as mentioned below. This .pro file does fall under the
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
# jni.h and jni_md.h are part of the Oracle JDK.
# They are modified for optimization within the context of the project.
# However, the modifications do not change the behavior of the JNI or
# invalidate any part of the JNI documentation.
#------------------------------------------------------------------------

#------------------------------------------------------------------------
# .pro file for the Java-C++ bridge.
# This subproject contains the functionality required to bridge the gap
# between Java and C++. The JACE library is used for that purpose.
# JACE has been optimized for use with PowerGrid.
#------------------------------------------------------------------------

QT          = core concurrent
TEMPLATE    = lib
TARGET      = Bridge
CONFIG     += staticlib thread c++11

# Tell JACE we're exporting symbols, and want to load the JVM dynamically.
DEFINES += JACE_WANT_DYNAMIC_LOAD JACE_STATIC

# In debug mode, have JACE check for null values
# and out-of-bounds array indices
CONFIG(debug, debug|release): DEFINES += JACE_CHECK_NULLS JACE_CHECK_ARRAYS


win32 {
    # Windows has this specific VmLoader
    SOURCES += jace/Win32VmLoader.cpp
    HEADERS += jace/Win32VmLoader.h
}

HEADERS += \
    jace/MappingUnavailableException.h \
    jace/RSClass.h \
    jace/RSClassMapper.h \
    jace/UpdaterRunner.h \
    rs/client.h \
    java/lang/object.h \
    java/lang/string.h \
    MethodHelper.h \
    rs/abstractcamera.h \
    rs/abstractcameralocationdata.h \
    rs/abstractcentrallocationdata.h \
    rs/abstractmodel.h \
    rs/abstractserver.h \
    rs/abstractsocketstream.h \
    rs/animablenode.h \
    rs/animatedobject.h \
    rs/animation.h \
    rs/baseinfo.h \
    rs/canvas.h \
    rs/detailinfo.h \
    rs/entityposition.h \
    rs/fileworker.h \
    rs/friend.h \
    rs/grandexchangeoffer.h \
    rs/graphicstoolkit.h \
    rs/hintarrow.h \
    rs/animator.h \
    rs/cameramatrix.h \
    rs/chatline.h \
    rs/entitydata.h \
    rs/entitynode.h \
    rs/grounddata.h \
    rs/isaaccipher.h \
    rs/interactable.h \
    rs/node.h \
    rs/animable.h \
    rs/deque.h \
    rs/boundary.h \
    rs/hashtable.h \
    rs/hashtableiterator.h \
    rs/camera.h \
    rs/detailinfonode.h \
    rs/floordecoration.h \
    rs/groundentity.h \
    rs/groundobject.h \
    rs/animatedanimableobject.h \
    rs/animatedboundaryobject.h \
    rs/itemnode.h \
    rs/mlstring.h \
    rs/passiveanimator.h \
    rs/quaternion.h \
    rs/skillinfo.h \
    rs/sprite.h \
    rs/worldcontroller.h \
    rs/interface.h \
    rs/nodesub.h \
    rs/stream.h \
    rs/reference.h \
    rs/queue.h \
    rs/cache.h \
    rs/floatstream.h \
    rs/toolkitld.h \
    rs/varpbits.h \
    rs/facade.h \
    rs/linkedlistnode.h \
    rs/linkedlist.h \
    rs/modelld.h \
    rs/objectcomposite.h \
    rs/nodesubqueue.h \
    rs/objectdefloader.h \
    rs/objectdef.h \
    rs/itemdefloader.h \
    rs/itemdef.h \
    rs/overheadmessage.h \
    rs/lookuptable.h \
    rs/menugroupnode.h \
    rs/menuitemnode.h \
    rs/referencetable.h \
    rs/server.h \
    rs/npcdefloader.h \
    rs/npcdef.h \
    rs/walldecoration.h \
    rs/combatinfo.h \
    rs/animableobject.h \
    rs/animatedfloorobject.h \
    rs/animatedwallobject.h \
    rs/boundaryobject.h \
    rs/cameralocationdata.h \
    rs/wallobject.h \
    rs/landscape.h \
    rs/interfacechild.h \
    rs/interfacenode.h \
    rs/interactableanimator.h \
    rs/playerdef.h \
    rs/centrallocationdata.h \
    rs/character.h \
    rs/chatmessage.h \
    rs/chatchannel.h \
    rs/player.h \
    rs/spriteld.h \
    rs/projectile.h \
    rs/projectilenode.h \
    rs/npc.h \
    rs/npcnode.h \
    rs/modelopengl.h \
    rs/packetstream.h \
    rs/tile.h \
    rs/toolkitopengl.h \
    rs/modeldirectx.h \
    rs/filesystem.h \
    rs/combatinfonode.h \
    rs/dequenode.h \
    rs/floorobject.h \
    rs/hardreference.h \
    java/io/file.h \
    rs/landscapedetails.h \
    rs/landscapeinfo.h \
    java/io/inputstream.h \
    java/io/outputstream.h \
    rs/groundbytes.h \
    java/lang/ref/softreference.h \
    java/util/map.h \
    java/awt/rectangle.h \
    java/util/zip/inflater.h \
    rs/fileondisk.h \
    rs/gzipdecompressor.h \
    java/awt/graphicsdevice.h \
    java/awt/displaymode.h \
    rs/graphics.h \
    java/net/socket.h \
    rs/inputstream.h \
    rs/softreference.h \
    rs/outputstream.h \
    rs/socketstream.h \
    rs/grounditem.h \
    java/awt/event/mouseevent.h \
    java/awt/component.h \
    java/awt/event/keyevent.h \
    namespace.h \
    net/pgrid/loader/pgloader.h \
    jace/macvmloader.h \
    rs/toolkitdirectx.h \
    rs/mouselistener.h \
    rs/keylistener.h \
    rs/keydata.h \
    rs/mousedata.h \
    rs/abstractmouselistener.h \
    java/lang/java_class.h

SOURCES += \
    jace/MappingUnavailableException.cpp \
    jace/RSClass.cpp \
    jace/RSClassMapper.cpp \
    jace/UpdaterRunner.cpp \
    rs/client.cpp \
    java/lang/object.cpp \
    java/lang/string.cpp \
    rs/abstractcamera.cpp \
    rs/abstractcameralocationdata.cpp \
    rs/abstractcentrallocationdata.cpp \
    rs/abstractmodel.cpp \
    rs/abstractserver.cpp \
    rs/abstractsocketstream.cpp \
    rs/animablenode.cpp \
    rs/animatedobject.cpp \
    rs/animation.cpp \
    rs/baseinfo.cpp \
    rs/canvas.cpp \
    rs/detailinfo.cpp \
    rs/entityposition.cpp \
    rs/fileworker.cpp \
    rs/friend.cpp \
    rs/grandexchangeoffer.cpp \
    rs/graphicstoolkit.cpp \
    rs/hintarrow.cpp \
    rs/animator.cpp \
    rs/cameramatrix.cpp \
    rs/chatline.cpp \
    rs/entitydata.cpp \
    rs/entitynode.cpp \
    rs/grounddata.cpp \
    rs/isaaccipher.cpp \
    rs/interactable.cpp \
    rs/node.cpp \
    rs/animable.cpp \
    rs/deque.cpp \
    rs/boundary.cpp \
    rs/hashtable.cpp \
    rs/hashtableiterator.cpp \
    rs/camera.cpp \
    rs/detailinfonode.cpp \
    rs/floordecoration.cpp \
    rs/groundentity.cpp \
    rs/groundobject.cpp \
    rs/animatedanimableobject.cpp \
    rs/animatedboundaryobject.cpp \
    rs/itemnode.cpp \
    rs/mlstring.cpp \
    rs/passiveanimator.cpp \
    rs/quaternion.cpp \
    rs/skillinfo.cpp \
    rs/sprite.cpp \
    rs/worldcontroller.cpp \
    rs/interface.cpp \
    rs/nodesub.cpp \
    rs/stream.cpp \
    rs/reference.cpp \
    rs/queue.cpp \
    rs/cache.cpp \
    rs/floatstream.cpp \
    rs/toolkitld.cpp \
    rs/varpbits.cpp \
    rs/facade.cpp \
    rs/linkedlistnode.cpp \
    rs/linkedlist.cpp \
    rs/modelld.cpp \
    rs/objectcomposite.cpp \
    rs/nodesubqueue.cpp \
    rs/objectdefloader.cpp \
    rs/objectdef.cpp \
    rs/itemdefloader.cpp \
    rs/itemdef.cpp \
    rs/overheadmessage.cpp \
    rs/lookuptable.cpp \
    rs/menugroupnode.cpp \
    rs/menuitemnode.cpp \
    rs/referencetable.cpp \
    rs/server.cpp \
    rs/npcdefloader.cpp \
    rs/npcdef.cpp \
    rs/walldecoration.cpp \
    rs/combatinfo.cpp \
    rs/animableobject.cpp \
    rs/animatedfloorobject.cpp \
    rs/animatedwallobject.cpp \
    rs/boundaryobject.cpp \
    rs/cameralocationdata.cpp \
    rs/wallobject.cpp \
    rs/landscape.cpp \
    rs/interfacechild.cpp \
    rs/interfacenode.cpp \
    rs/interactableanimator.cpp \
    rs/playerdef.cpp \
    rs/centrallocationdata.cpp \
    rs/character.cpp \
    rs/chatmessage.cpp \
    rs/chatchannel.cpp \
    rs/player.cpp \
    rs/spriteld.cpp \
    rs/projectile.cpp \
    rs/projectilenode.cpp \
    rs/npc.cpp \
    rs/npcnode.cpp \
    rs/modelopengl.cpp \
    rs/packetstream.cpp \
    rs/tile.cpp \
    rs/toolkitopengl.cpp \
    rs/modeldirectx.cpp \
    rs/filesystem.cpp \
    rs/combatinfonode.cpp \
    rs/dequenode.cpp \
    rs/floorobject.cpp \
    rs/hardreference.cpp \
    java/io/file.cpp \
    rs/landscapedetails.cpp \
    rs/landscapeinfo.cpp \
    rs/groundbytes.cpp \
    java/util/map.cpp \
    java/awt/rectangle.cpp \
    java/util/zip/inflater.cpp \
    rs/fileondisk.cpp \
    rs/gzipdecompressor.cpp \
    java/awt/graphicsdevice.cpp \
    java/awt/displaymode.cpp \
    rs/graphics.cpp \
    java/net/socket.cpp \
    rs/inputstream.cpp \
    rs/softreference.cpp \
    rs/outputstream.cpp \
    rs/socketstream.cpp \
    java/io/java_io_inputstream.cpp \
    java/io/java_io_outputstream.cpp \
    java/lang/ref/java_lang_ref_softreference.cpp \
    rs/grounditem.cpp \
    java/awt/event/mouseevent.cpp \
    java/awt/event/keyevent.cpp \
    java/awt/java_awt_component.cpp \
    net/pgrid/loader/pgloader.cpp \
    jace/macvmloader.cpp \
    rs/toolkitdirectx.cpp \
    rs/keylistener.cpp \
    rs/keydata.cpp \
    rs/mousedata.cpp \
    rs/mouselistener.cpp \
    rs/abstractmouselistener.cpp \
    java/lang/java_class.cpp

HEADERS    += \
    jni.h \
    jni_md.h \
    jace/VmLoader.h \
    jace/UnixVmLoader.h \
    jace/os_dep.h \
    jace/OptionList.h \
    jace/JSignature.h \
    jace/JNIHelper.h \
    jace/JNIException.h \
    jace/JFieldProxyHelper.h \
    jace/JFieldProxy.h \
    jace/JFieldHelper.h \
    jace/JField.h \
    jace/JFactory.h \
    jace/JConstructor.h \
    jace/JClassImpl.h \
    jace/JClass.h \
    jace/javacast.h \
    jace/JArray.h \
    jace/JArguments.h \
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
    jace/proxy/types/JBoolean.h

SOURCES    += \
    jace/VmLoader.cpp \
    jace/UnixVmLoader.cpp \
    jace/os_dep.cpp \
    jace/OptionList.cpp \
    jace/JSignature.cpp \
    jace/JNIHelper.cpp \
    jace/JNIException.cpp \
    jace/JFieldProxyHelper.cpp \
    jace/JFieldProxy.cpp \
    jace/JFieldHelper.cpp \
    jace/JField.cpp \
    jace/JFactory.cpp \
    jace/JConstructor.cpp \
    jace/JClassImpl.cpp \
    jace/JClass.cpp \
    jace/javacast.cpp \
    jace/JArray.cpp \
    jace/JArguments.cpp \
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
