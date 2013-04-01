package powergrid.model.world;

import java.util.ArrayList;
import java.util.Objects;
import org.powerbot.game.api.wrappers.Locatable;
import org.powerbot.game.api.wrappers.RegionOffset;
import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.client.CombatStatus;
import org.powerbot.game.client.CombatStatusData;
import org.powerbot.game.client.LinkedList;
import org.powerbot.game.client.LinkedListNode;
import org.powerbot.game.client.RSAnimator;
import org.powerbot.game.client.RSCharacter;
import org.powerbot.game.client.RSMessageData;
import powergrid.model.Point;

/**
 * Represents a mobile entity in the Runescape World.
 * @author Chronio
 */
public abstract class Mobile implements Locatable {
    
    private RSCharacter rscharacter;
    private Point position;
    
    /**
     * Creates a Mobile object with the specified RSCharacter object.
     * @param rscharacter the RSCharacter object this Mobile represents.
     */
    public Mobile(RSCharacter rscharacter){
        assert rscharacter != null;
        this.rscharacter = rscharacter;
    }

    /**
     * @return the linked RSCharacter Object.
     */
    public RSCharacter getRSCharacter() {
        return rscharacter;
    }   

    /**
     * @return the last known position of this Mobile.
     */
    public Point getPosition() {
        return position;
    }

    /**
     * Updates the position of this Mobile.
     * @param position the new position
     */
    public void setPosition(Point position) {
        assert position != null;
        this.position = position;
    }
    
    /**
     * @return the ID of this Mobile.
     */
    public abstract int getID();
    
    /**
     * @return the level of this Mobile.
     */
    public abstract int getLevel();
    
    /**
     * @return the name of this Mobile
     */
    public abstract String getName();
    
    /**
     * @return an array containing the actions of this Mobile.
     */
    public abstract String[] getActions();
    
    /**
     * @return the integer specifying the prayer icon of this Mobile
     */
    public abstract int getPrayerIcon();
    
    /**
     * @return the actual movement speed of this Mobile
     */
    public int getMoveSpeed() {
        return getRSCharacter().isMoving();
    }
    
    /**
     * @return whether this Mobile is moving (<code>getMoveSpeed() != 0</code>)
     */
    public boolean isMoving() {
        return getMoveSpeed() != 0;
    }
    
    /**
     * @return the integer specifying the animation of this Mobile
     */
    public int getAnimation() {
        RSAnimator anim = getRSCharacter().getAnimation();
        return (anim == null ? -1 : anim.getSequence().getID());
    }
    
    /**
     * @return the message of this Mobile.
     */
    public String getMessage() {
        RSMessageData mData = getRSCharacter().getMessageData();
        return (mData == null ? null : mData.getMessage());
    }
    
    /**
     * Collects the CombatStatusData objects from the underlying RSCharacter object.
     * <p/>
     * This data has to be parsed from an internal LinkedList and is therefore 
     * considerably slow.
     * <p/>
     * @return an array with the CombatStatusData objects from the underlying
     *         RSCharacter object.
     */
    public CombatStatusData[] getCombatStatusData() {
        LinkedList list = getRSCharacter().getCombatStatusList();
        if (list == null) {
            return null;
        }
        LinkedListNode head = list.getTail();
        if (head == null) {
            return null;
        }
        LinkedListNode current = head;
        ArrayList<CombatStatusData> res = new ArrayList<>(3);
        while (current.getNext() == head) {
            if (current instanceof CombatStatus) {
                CombatStatus status = (CombatStatus) current;
                LinkedList statusList = status.getData();
                res.add((CombatStatusData) statusList.getTail().getNext());
            }
        }
        return res.toArray(new CombatStatusData[res.size()]);
    }
    
    /**
     * Collects the amount of health this Mobile has.
     * <p/>
     * This method collects the required data using the 
     * <code>getCombatStatusData()</code>, meaning that repetitive calls of 
     * this method may lead to performance issues. Try to prevent calling this 
     * method too often unless the value is expected to have changed.
     * <p/>
     * @return the current amount of health of this Mobile in the range 0 to 1,
     *         or 1 if the health could not be determined.
     */
    public double getHealth() {
        CombatStatusData[] cStatus = getCombatStatusData();
        if (cStatus != null && cStatus.length > 1) {
            CombatStatusData data = cStatus[1];
            if (data != null) {
                return data.getHPRatio() / 255d;
            }
        }
        return 1d;
    }
    
    /**
     * Collects the amount of adrenaline this Mobile has.
     * <p/>
     * This method collects the required data using the 
     * <code>getCombatStatusData()</code>, meaning that repetitive calls of 
     * this method may lead to performance issues. Try to prevent calling this 
     * method too often unless the value is expected to have changed.
     * <p/>
     * @return the current amount of adrenaline of this Mobile in the range 0 
     *         to 1, or 0 if the adrenaline could not be determined.
     */
    public double getAdrenaline() {
        CombatStatusData[] cStatus = getCombatStatusData();
        if (cStatus != null && cStatus.length > 0) {
            CombatStatusData data = cStatus[0];
            if (data != null) {
                return data.getHPRatio() / 255d;
            }
        }
        return 0d;
    }
    
    @Override 
    public boolean equals(Object other) {
        if (other instanceof Mobile) {
            Mobile that = (Mobile) other;
            return this.getPosition().equals(that.getPosition()) &&
                    Objects.equals(this.getRSCharacter(), that.getRSCharacter());
        }
        return false;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 67 * hash + Objects.hashCode(this.rscharacter);
        hash = 67 * hash + Objects.hashCode(this.position);
        return hash;
    }
    
    @Override 
    public String toString() {
        StringBuilder sb = new StringBuilder("Person: ");
        sb.append(getName()).append(" (Level ").append(getLevel()).append(")");
        return sb.toString();
    }

    @Override
    @Deprecated
    public RegionOffset getRegionOffset() {
        return getPosition().getRegionOffset();
    }

    @Override
    public Tile getLocation() {
        return getPosition().getLocation();
    }
}
