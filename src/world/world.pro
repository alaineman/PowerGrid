#------------------------------------------------
#
# .pro file for the world representation.
#
# The classes in this subproject all represent
# objects from the Runescape environment.
#
#------------------------------------------------

QT       -= gui

TARGET = world
TEMPLATE = lib
CONFIG += staticlib

DESTDIR = build/
OBJECTS_DIR = build/

SOURCES += \    
    vector3d.cpp \
    Entity/renderableentity.cpp \
    Entity/animableentity.cpp \
    DataStructure/linkedlist.cpp \
    DataStructure/linkedlistnode.cpp \
    Entity/animator.cpp \
    Entity/animation.cpp \
    Entity/Character/npc.cpp \
    Entity/Character/player.cpp \
    Entity/Character/character.cpp \
    Entity/Character/characteranimator.cpp \
    Entity/Character/playercomposite.cpp \
    Entity/Character/overheadmessage.cpp \
    Entity/Character/npccomposite.cpp \    
    Entity/animableentitynode.cpp \
    Node/cachablenode.cpp \    
    DataStructure/hashtable.cpp \
    client.cpp \
    engine.cpp \
    DataStructure/deque.cpp \
    Node/dequenode.cpp \
    Local/skilldata.cpp \
    Local/playerfacade.cpp \
    Local/widgetcomponent.cpp \
    Local/varps.cpp \
    Local/grandexchangeoffer.cpp \
    Local/hintarrow.cpp \
    Cache/objectcacheloader.cpp \
    Cache/npccacheloader.cpp \
    Cache/itemcacheloader.cpp \
    Cache/graphiccacheloader.cpp \
    Landscape/landscapedata.cpp \
    Landscape/mapbase.cpp \
    Landscape/landscapedetails.cpp \
    Landscape/collisiondata.cpp \
    Landscape/tile.cpp \
    Landscape/tileheights.cpp \
    Entity/groundentity.cpp \
    Graphic/model.cpp \
    Graphic/directxmodel.cpp \
    Graphic/graphicstoolkit.cpp \
    Graphic/matrix4f.cpp \
    Graphic/directxtoolkit.cpp \
    Graphic/graphic.cpp \
    reference.cpp \
    softreference.cpp \
    hardreference.cpp \
    DataStructure/queue.cpp \
    Node/node.cpp \
    Entity/entitydata.cpp \
    Entity/entity.cpp \
    Cache/cache.cpp \
    DataStructure/objectnode.cpp \
    Local/widget.cpp

HEADERS += \    
    point.h \    
    vector3d.h \
    Entity/renderableentity.h \
    Entity/animableentity.h \
    DataStructure/linkedlist.h \
    DataStructure/linkedlistnode.h \
    Entity/animator.h \
    Entity/animation.h \
    Entity/Character/npc.h \
    Entity/Character/player.h \
    Entity/Character/character.h \
    Entity/Character/characteranimator.h \
    Entity/Character/playercomposite.h \
    Entity/Character/overheadmessage.h \
    Entity/Character/npccomposite.h \
    Entity/animableentitynode.h \
    Node/cachablenode.h \    
    DataStructure/hashtable.h \
    client.h \
    engine.h \
    DataStructure/deque.h \
    Node/dequenode.h \    
    Local/skilldata.h \
    Local/playerfacade.h \
    Local/widgetcomponent.h \
    Local/widget.h \
    Local/varps.h \
    Local/grandexchangeoffer.h \
    Local/hintarrow.h \
    Cache/objectcacheloader.h \
    Cache/npccacheloader.h \
    Cache/itemcacheloader.h \
    Cache/graphiccacheloader.h \
    Landscape/landscapedata.h \
    Landscape/mapbase.h \
    Landscape/landscapedetails.h \
    Landscape/collisiondata.h \
    Landscape/tile.h \
    Landscape/tileheights.h \
    Entity/groundentity.h \
    Graphic/model.h \
    Graphic/directxmodel.h \
    Graphic/graphicstoolkit.h \
    Graphic/matrix4f.h \
    Graphic/directxtoolkit.h \
    Graphic/graphic.h \
    reference.h \
    softreference.h \
    hardreference.h \
    DataStructure/queue.h \
    Node/node.h \
    Entity/entitydata.h \
    Entity/entity.h \
    Cache/cache.h \
    DataStructure/objectnode.h

OTHER_FILES += \
    includeWorld.pro

#------------------------------------------------
# The subprojects this project depends on
#------------------------------------------------
include (../JNIModule/includeJNI.pro)
