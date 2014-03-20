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

# JACE uses .tsd and .tsp files as C++ header files, so include those as well
QMAKE_EXT_H += .tsp .tsd

# Tell JACE we're exporting symbols, and want to load the JVM dynamically.
DEFINES += JACE_WANT_DYNAMIC_LOAD JACE_EXPORTS JACE_PROXY_EXPORTS

# In debug mode, have JACE check for null values
# and out-of-bounds array indices
CONFIG(debug, debug|release): DEFINES += JACE_CHECK_NULLS JACE_CHECK_ARRAYS

HEADERS += \
    jace/MappingUnavailableException.h \
    jace/RSClass.h \
    jace/RSClassMapper.h \
    jace/UpdaterRunner.h \
    api/bridge/client.h \
    java/lang/object.h \
    java/lang/string.h \
    MethodHelper.h \
    api/bridge/abstractcamera.h \
    api/bridge/abstractcameralocationdata.h \
    api/bridge/abstractcentrallocationdata.h \
    api/bridge/abstractmodel.h \
    api/bridge/abstractserver.h \
    api/bridge/abstractsocketstream.h \
    api/bridge/animablenode.h \
    api/bridge/animatedobject.h \
    api/bridge/animation.h \
    api/bridge/baseinfo.h \
    api/bridge/canvas.h \
    api/bridge/detailinfo.h \
    api/bridge/entityposition.h \
    api/bridge/fileworker.h \
    api/bridge/friend.h \
    api/bridge/grandexchangeoffer.h \
    api/bridge/graphicstoolkit.h \
    api/bridge/hintarrow.h \
    api/bridge/animator.h \
    api/bridge/cameramatrix.h \
    api/bridge/chatline.h \
    api/bridge/entitydata.h \
    api/bridge/entitynode.h \
    api/bridge/grounddata.h \
    api/bridge/isaaccipher.h \
    api/bridge/interactable.h \
    api/bridge/node.h \
    api/bridge/animable.h \
    api/bridge/deque.h \
    api/bridge/boundary.h \
    api/bridge/hashtable.h \
    api/bridge/hashtableiterator.h \
    api/bridge/camera.h \
    api/bridge/detailinfonode.h \
    api/bridge/floordecoration.h \
    api/bridge/groundentity.h \
    api/bridge/groundobject.h \
    api/bridge/animatedanimableobject.h \
    api/bridge/animatedboundaryobject.h \
    api/bridge/itemnode.h \
    api/bridge/keyboard.h \
    api/bridge/mlstring.h \
    api/bridge/mouse.h \
    api/bridge/passiveanimator.h \
    api/bridge/quaternion.h \
    api/bridge/skillinfo.h \
    api/bridge/sprite.h \
    api/bridge/worldcontroller.h \
    api/bridge/interface.h \
    api/bridge/nodesub.h \
    api/bridge/stream.h \
    api/bridge/reference.h \
    api/bridge/queue.h \
    api/bridge/cache.h \
    api/bridge/floatstream.h \
    api/bridge/toolkitld.h \
    api/bridge/varpbits.h \
    api/bridge/facade.h \
    api/bridge/linkedlistnode.h \
    api/bridge/linkedlist.h \
    api/bridge/modelld.h \
    api/bridge/objectcomposite.h \
    api/bridge/nodesubqueue.h \
    api/bridge/objectdefloader.h \
    api/bridge/objectdef.h \
    api/bridge/itemdefloader.h \
    api/bridge/itemdef.h \
    api/bridge/overheadmessage.h \
    api/bridge/lookuptable.h \
    api/bridge/menugroupnode.h \
    api/bridge/menuitemnode.h \
    api/bridge/referencetable.h \
    api/bridge/server.h \
    api/bridge/npcdefloader.h \
    api/bridge/npcdef.h \
    api/bridge/walldecoration.h \
    api/bridge/combatinfo.h \
    api/bridge/animableobject.h \
    api/bridge/animatedfloorobject.h \
    api/bridge/animatedwallobject.h \
    api/bridge/boundaryobject.h \
    api/bridge/cameralocationdata.h \
    api/bridge/wallobject.h \
    api/bridge/landscape.h \
    api/bridge/interfacechild.h \
    api/bridge/interfacenode.h \
    api/bridge/interactableanimator.h \
    api/bridge/playerdef.h \
    api/bridge/centrallocationdata.h \
    api/bridge/character.h \
    api/bridge/chatmessage.h \
    api/bridge/chatchannel.h \
    api/bridge/player.h \
    api/bridge/spriteld.h \
    api/bridge/projectile.h \
    api/bridge/projectilenode.h \
    api/bridge/npc.h \
    api/bridge/npcnode.h \
    api/bridge/modelopengl.h \
    api/bridge/packetstream.h \
    api/bridge/tile.h \
    api/bridge/toolkitopengl.h \
    api/bridge/modeldirectx.h \
    api/bridge/filesystem.h \
    api/bridge/combatinfonode.h \
    api/bridge/dequenode.h \
    api/bridge/floorobject.h \
    api/bridge/hardreference.h \
    java/io/file.h \
    api/bridge/landscapedetails.h \
    api/bridge/landscapeinfo.h \
    java/io/inputstream.h \
    java/io/outputstream.h \
    api/bridge/groundbytes.h \
    java/lang/ref/softreference.h \
    java/util/map.h \
    java/awt/rectangle.h \
    java/util/zip/inflater.h \
    api/bridge/fileondisk.h \
    api/bridge/gzipdecompressor.h \
    java/awt/graphicsdevice.h \
    java/awt/displaymode.h \
    api/bridge/graphics.h \
    java/net/socket.h \
    api/bridge/inputstream.h \
    api/bridge/softreference.h \
    api/bridge/outputstream.h \
    api/bridge/socketstream.h \
    api/bridge/grounditem.h \
    java/awt/event/mouseevent.h \
    java/awt/component.h \
    java/awt/event/keyevent.h \
    namespace.h \
    entity/component.h \
    entity/entity.h \
    entity/world.h \
    api/component/position.h \
    api/component/size.h \
    api/component/id.h \
    api/component/name.h \
    api/component/speed.h \
    api/component/interaction.h \
    api/component/action.h \
    entity/matcher.h \
    api/component/transportation.h \
    entity/mapper.h

SOURCES += \
    jace/MappingUnavailableException.cpp \
    jace/RSClass.cpp \
    jace/RSClassMapper.cpp \
    jace/UpdaterRunner.cpp \
    api/bridge/client.cpp \
    java/lang/object.cpp \
    java/lang/string.cpp \
    api/bridge/abstractcamera.cpp \
    api/bridge/abstractcameralocationdata.cpp \
    api/bridge/abstractcentrallocationdata.cpp \
    api/bridge/abstractmodel.cpp \
    api/bridge/abstractserver.cpp \
    api/bridge/abstractsocketstream.cpp \
    api/bridge/animablenode.cpp \
    api/bridge/animatedobject.cpp \
    api/bridge/animation.cpp \
    api/bridge/baseinfo.cpp \
    api/bridge/canvas.cpp \
    api/bridge/detailinfo.cpp \
    api/bridge/entityposition.cpp \
    api/bridge/fileworker.cpp \
    api/bridge/friend.cpp \
    api/bridge/grandexchangeoffer.cpp \
    api/bridge/graphicstoolkit.cpp \
    api/bridge/hintarrow.cpp \
    api/bridge/animator.cpp \
    api/bridge/cameramatrix.cpp \
    api/bridge/chatline.cpp \
    api/bridge/entitydata.cpp \
    api/bridge/entitynode.cpp \
    api/bridge/grounddata.cpp \
    api/bridge/isaaccipher.cpp \
    api/bridge/interactable.cpp \
    api/bridge/node.cpp \
    api/bridge/animable.cpp \
    api/bridge/deque.cpp \
    api/bridge/boundary.cpp \
    api/bridge/hashtable.cpp \
    api/bridge/hashtableiterator.cpp \
    api/bridge/camera.cpp \
    api/bridge/detailinfonode.cpp \
    api/bridge/floordecoration.cpp \
    api/bridge/groundentity.cpp \
    api/bridge/groundobject.cpp \
    api/bridge/animatedanimableobject.cpp \
    api/bridge/animatedboundaryobject.cpp \
    api/bridge/itemnode.cpp \
    api/bridge/keyboard.cpp \
    api/bridge/mlstring.cpp \
    api/bridge/mouse.cpp \
    api/bridge/passiveanimator.cpp \
    api/bridge/quaternion.cpp \
    api/bridge/skillinfo.cpp \
    api/bridge/sprite.cpp \
    api/bridge/worldcontroller.cpp \
    api/bridge/interface.cpp \
    api/bridge/nodesub.cpp \
    api/bridge/stream.cpp \
    api/bridge/reference.cpp \
    api/bridge/queue.cpp \
    api/bridge/cache.cpp \
    api/bridge/floatstream.cpp \
    api/bridge/toolkitld.cpp \
    api/bridge/varpbits.cpp \
    api/bridge/facade.cpp \
    api/bridge/linkedlistnode.cpp \
    api/bridge/linkedlist.cpp \
    api/bridge/modelld.cpp \
    api/bridge/objectcomposite.cpp \
    api/bridge/nodesubqueue.cpp \
    api/bridge/objectdefloader.cpp \
    api/bridge/objectdef.cpp \
    api/bridge/itemdefloader.cpp \
    api/bridge/itemdef.cpp \
    api/bridge/overheadmessage.cpp \
    api/bridge/lookuptable.cpp \
    api/bridge/menugroupnode.cpp \
    api/bridge/menuitemnode.cpp \
    api/bridge/referencetable.cpp \
    api/bridge/server.cpp \
    api/bridge/npcdefloader.cpp \
    api/bridge/npcdef.cpp \
    api/bridge/walldecoration.cpp \
    api/bridge/combatinfo.cpp \
    api/bridge/animableobject.cpp \
    api/bridge/animatedfloorobject.cpp \
    api/bridge/animatedwallobject.cpp \
    api/bridge/boundaryobject.cpp \
    api/bridge/cameralocationdata.cpp \
    api/bridge/wallobject.cpp \
    api/bridge/landscape.cpp \
    api/bridge/interfacechild.cpp \
    api/bridge/interfacenode.cpp \
    api/bridge/interactableanimator.cpp \
    api/bridge/playerdef.cpp \
    api/bridge/centrallocationdata.cpp \
    api/bridge/character.cpp \
    api/bridge/chatmessage.cpp \
    api/bridge/chatchannel.cpp \
    api/bridge/player.cpp \
    api/bridge/spriteld.cpp \
    api/bridge/projectile.cpp \
    api/bridge/projectilenode.cpp \
    api/bridge/npc.cpp \
    api/bridge/npcnode.cpp \
    api/bridge/modelopengl.cpp \
    api/bridge/packetstream.cpp \
    api/bridge/tile.cpp \
    api/bridge/toolkitopengl.cpp \
    api/bridge/modeldirectx.cpp \
    api/bridge/filesystem.cpp \
    api/bridge/combatinfonode.cpp \
    api/bridge/dequenode.cpp \
    api/bridge/floorobject.cpp \
    api/bridge/hardreference.cpp \
    java/io/file.cpp \
    api/bridge/landscapedetails.cpp \
    api/bridge/landscapeinfo.cpp \
    api/bridge/groundbytes.cpp \
    java/util/map.cpp \
    java/awt/rectangle.cpp \
    java/util/zip/inflater.cpp \
    api/bridge/fileondisk.cpp \
    api/bridge/gzipdecompressor.cpp \
    java/awt/graphicsdevice.cpp \
    java/awt/displaymode.cpp \
    api/bridge/graphics.cpp \
    java/net/socket.cpp \
    api/bridge/inputstream.cpp \
    api/bridge/softreference.cpp \
    api/bridge/outputstream.cpp \
    api/bridge/socketstream.cpp \
    java/io/java_io_inputstream.cpp \
    java/io/java_io_outputstream.cpp \
    java/lang/ref/java_lang_ref_softreference.cpp \
    api/bridge/grounditem.cpp \
    java/awt/event/mouseevent.cpp \
    java/awt/event/keyevent.cpp \
    entity/component.cpp \
    entity/entity.cpp \
    entity/world.cpp \
    api/component/position.cpp \
    api/component/size.cpp \
    java/awt/java_awt_component.cpp \
    api/component/id.cpp \
    api/component/name.cpp \
    api/component/speed.cpp \
    api/component/interaction.cpp \
    api/component/action.cpp \
    entity/matcher.cpp \
    api/component/transportation.cpp \
    entity/mapper.cpp

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
    jace/JMethod.h \
    jace/JFieldProxyHelper.h \
    jace/JFieldProxy.h \
    jace/JFieldHelper.h \
    jace/JField.h \
    jace/JFactory.h \
    jace/JConstructor.h \
    jace/JClassImpl.h \
    jace/JClass.h \
    jace/javacast.h \
    jace/JArrayHelper.h \
    jace/JArray.tsd \
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
    jace/proxy/types/JBoolean.h \
    jace/JMethod.tsp \
    jace/JMethod.tsd \
    jace/JField.tsp \
    jace/JField.tsd \
    jace/javacast.tsp \
    jace/javacast.tsd \
    jace/JArray.tsp

SOURCES    += \
    jace/VmLoader.cpp \
    jace/UnixVmLoader.cpp \
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
    jace/JConstructor.cpp \
    jace/JClassImpl.cpp \
    jace/JClass.cpp \
    jace/javacast.cpp \
    jace/JArrayHelper.cpp \
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
