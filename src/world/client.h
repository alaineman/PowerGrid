#ifndef CLIENT_H
#define CLIENT_H

#include "jniobject.h"
#include "engine.h"
#include "Cache/cache.h"
#include "Entity/Character/player.h"
#include "DataStructure/hashtable.h"
#include "DataStructure/deque.h"
#include "DataStructure/objectnode.h"
#include "Local/widget.h"
#include "Local/playerfacade.h"
#include "Local/grandexchangeoffer.h"
#include "Local/hintarrow.h"
#include "Cache/npccacheloader.h"
#include "Cache/itemcacheloader.h"
#include "Cache/graphiccacheloader.h"
#include "Landscape/landscapedata.h"

namespace world {

class Client : public Engine {
private:
    Q_DISABLE_COPY(Client)
    jint majorversion;
    jint minorversion;
    jint fps;
    jint hudindex;
    jint mousecrosshairstate;
    jint mousecrosshaireexpansionstate;
    jint camerayaw;
    jint camerapitch;
    jint destinationx;
    jint destinationy;
    jboolean spellselected;
    Cache* playermodelcache;
    Deque* loadedprojectiles;
    vector<HintArrow*> hintarrows;
    vector<GrandExchangeOffer*> geoffers;
    Player* localplayer;
    vector<Player*> loadedplayers;
    vector<ObjectNode*> loadednpcs;
    HashTable* loadednpctable;
    HashTable* loadedgrounditems;
    vector<Widget*> loadedwidgets;
    PlayerFacade* playerfacade;
    LandscapeData* landscapedata;
    NpcCacheLoader* npccacheloader;
    ItemCacheLoader* itemcacheloader;
    GraphicCacheLoader* graphicsloader;

public:
    Client(jobject obj) : Engine(obj){}
    jint getMajorVersion(bool useCache = true);
    jint getMinorVersion(bool useCache = true);
    jint getFps(bool useCache = true);
    jint getHudIndex(bool useCache = true);
    jint getMouseCrosshairState(bool useCache = true);
    jint getMouseCrosshairExpansionState(bool useCache = true);
    jint getCameraYaw(bool useCache = true);
    jint getCameraPitch(bool useCache = true);
    jint getDestinationX(bool useCache = true);
    jint getDestinationY(bool useCache = true);
    jboolean isSpellSelected(bool useCache = true);
    Cache* getPlayerModelCache(bool useCache = true);
    Deque* getLoadedProjectiles(bool useCache = true);
    vector<HintArrow*> getHintArrows(bool useCache = true);
    vector<GrandExchangeOffer*> getGrandExchangeOffers(bool useCache = true);
    Player* getLocalPlayer(bool useCache = true);
    vector<Player*> getLoadedPlayers(bool useCache = true);
    vector<ObjectNode*> getLoadedNpcArray(bool useCache = true);
    HashTable* getLoadedNpcTable(bool useCache = true);
    HashTable* getLoadedGroundItems(bool useCache = true);
    vector<Widget*> getLoadedWidgets(bool useCache = true);
    PlayerFacade* getPlayerFacade(bool useCache = true);
    LandscapeData* getLandscapeData(bool useCache = true);
    NpcCacheLoader* getNpcCacheLoader(bool useCache = true);
    ItemCacheLoader* getItemCacheLoader(bool useCache = true);
    GraphicCacheLoader* getGraphicCacheLoader(bool useCache = true);
};

}

#endif // CLIENT_H
