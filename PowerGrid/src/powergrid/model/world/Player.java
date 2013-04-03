package powergrid.model.world;

import org.powerbot.game.client.RSPlayer;

/**
 * This class represents a Player in Runescape.
 * @author Chronio
 */
public class Player extends Mobile {

    private RSPlayer player;
    
    /**
     * Creates a new Player that represents the given RSPlayer
     * @param player the RSPlayer this Player represents
     */
    public Player(RSPlayer player) {
        super(player);
        this.player = player;
    }

    @Override
    public RSPlayer getRSCharacter() {
        return player;
    }
    
    @Override
    public int getID() {
        //XXX Chronio: "I'm not sure about this ID value, please verify"
        return getRSCharacter().getComposite().getNPCID();
    }

    @Override
    public int getLevel() {
        return getRSCharacter().getLevel();
    }

    @Override
    public String getName() {
        return getRSCharacter().getName();
    }

    @Override
    public String[] getActions() {
        //XXX Chronio: "How can we find this out? It's not in the RSPlayerComposite"
        return new String[0];
    }

    @Override
    public int getPrayerIcon() {
        return getRSCharacter().getPrayerIcon();
    }
    
    /**
     * @return an integer specifying the Player's Skull icon.
     */
    public int getSkullIcon() {
        return getRSCharacter().getSkullIcon();
    }
    
    /**
     * @return an integer specifying the Player's Team.
     */
    public int getTeam() {
        return getRSCharacter().getTeam();
    }
    
}
