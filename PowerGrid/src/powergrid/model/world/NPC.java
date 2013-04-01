package powergrid.model.world;

import org.powerbot.game.client.RSNPC;

/**
 *
 * @author patrick
 */
public class NPC extends Mobile {

    private RSNPC npc;
    
    public NPC(RSNPC rsnpc) {
        super(rsnpc);
        npc = rsnpc;
    }

    @Override
    public RSNPC getRSCharacter() {
        return npc;
    }
    
    @Override
    public int getID() {
        return getRSCharacter().getRSNPCDef().getID();
    }

    @Override
    public int getLevel() {
        return getRSCharacter().getRSNPCDef().getLevel();
    }

    @Override
    public String getName() {
        return getRSCharacter().getRSNPCDef().getName();
    }

    @Override
    public String[] getActions() {
        return getRSCharacter().getRSNPCDef().getActions();
    }

    @Override
    public int getPrayerIcon() {
        return getRSCharacter().getRSNPCDef().getPrayerIcon();
    }
    
}
