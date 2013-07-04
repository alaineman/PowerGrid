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
    Entity/Character/npccomposite.cpp \    
    Entity/animableentitynode.cpp \
    Node/cachablenode.cpp \    
    DataStructure/hashtable.cpp \
    client.cpp \
    engine.cpp \
    DataStructure/deque.cpp \
    Node/dequenode.cpp \
    Local/playerfacade.cpp \
    Local/widgetcomponent.cpp \
    Local/varps.cpp \
    Local/grandexchangeoffer.cpp \
    Local/hintarrow.cpp \
    Cache/objectcacheloader.cpp \
    Cache/npccacheloader.cpp \
    Cache/itemcacheloader.cpp \
    Cache/graphiccacheloader.cpp \
    Landscape/collisiondata.cpp \
    Landscape/tile.cpp \
    Landscape/tileheights.cpp \
    Graphic/model.cpp \
    Graphic/directxmodel.cpp \
    Graphic/graphicstoolkit.cpp \
    Graphic/matrix4f.cpp \
    Graphic/directxtoolkit.cpp \
    Graphic/graphic.cpp \
    softreference.cpp \
    hardreference.cpp \
    DataStructure/queue.cpp \
    Node/node.cpp \
    Entity/entitydata.cpp \
    Entity/entity.cpp \
    Cache/cache.cpp \
    Local/widget.cpp \
    Graphic/openglmodel.cpp \
    Graphic/opengltoolkit.cpp \
    Entity/projectile.cpp \
    Entity/projectilenode.cpp \
    Entity/Character/combatbar.cpp \
    Entity/Character/combatbardata.cpp \
    Node/itemnode.cpp \
    Entity/itempile.cpp \
    Entity/itemdefinition.cpp \
    Graphic/javamodel.cpp \
    Graphic/javatoolkit.cpp \
    Local/skill.cpp \
    Local/skillcomposite.cpp \
    Entity/Character/chatmessage.cpp \
    Node/itemstorage.cpp \
    Entity/SceneObject/floordecoration.cpp \
    Entity/SceneObject/animatedfloordecoration.cpp \
    Landscape/regionbase.cpp \
    Landscape/regiongrid.cpp \
    Landscape/region.cpp \
    Entity/boundary.cpp \
    Entity/SceneObject/eventobject.cpp \
    Entity/SceneObject/animatedwalldecoration.cpp \
    Entity/SceneObject/animatedeventobject.cpp \
    Entity/SceneObject/animatedboundary.cpp \
    Entity/SceneObject/objectcomposite.cpp \
    Entity/SceneObject/objectdefinition.cpp \
    Node/objectnode.cpp \
    Entity/SceneObject/walldecoration.cpp

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
    Entity/Character/npccomposite.h \
    Entity/animableentitynode.h \
    Node/cachablenode.h \    
    DataStructure/hashtable.h \
    client.h \
    engine.h \
    DataStructure/deque.h \
    Node/dequenode.h \    
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
    Landscape/collisiondata.h \
    Landscape/tile.h \
    Landscape/tileheights.h \
    Graphic/model.h \
    Graphic/directxmodel.h \
    Graphic/graphicstoolkit.h \
    Graphic/matrix4f.h \
    Graphic/directxtoolkit.h \
    Graphic/graphic.h \
    softreference.h \
    hardreference.h \
    DataStructure/queue.h \
    Node/node.h \
    Entity/entitydata.h \
    Entity/entity.h \
    Cache/cache.h \
    DataStructure/objectnode.h \
    Graphic/openglmodel.h \
    Graphic/opengltoolkit.h \
    Entity/projectile.h \
    Entity/projectilenode.h \
    Entity/Character/combatbar.h \
    Entity/Character/combatbardata.h \
    Node/itemnode.h \
    Entity/itempile.h \
    Entity/itemdefinition.h \
    Graphic/javamodel.h \
    Graphic/javatoolkit.h \
    Local/skill.h \
    Local/skillcomposite.h \
    Entity/Character/chatmessage.h \
    Node/itemstorage.h \
    Entity/SceneObject/floordecoration.h \
    Entity/SceneObject/animatedfloordecoration.h \
    Landscape/region.h \
    Landscape/regiongrid.h \
    Landscape/regionbase.h \
    Entity/animatedboundary.h \
    Entity/animatedeventobject.h \
    Entity/animatedwalldecoration.h \
    Entity/boundary.h \
    Entity/SceneObject/eventobject.h \
    Entity/SceneObject/animatedwalldecoration.h \
    Entity/SceneObject/animatedeventobject.h \
    Entity/SceneObject/animatedboundary.h \
    Entity/SceneObject/objectcomposite.h \
    Entity/SceneObject/objectdefinition.h \
    Node/objectnode.h \
    Entity/SceneObject/walldecoration.h

OTHER_FILES += \
    includeWorld.pro

#------------------------------------------------
# The subprojects this project depends on
#------------------------------------------------
include (../JNIModule/includeJNI.pro)
