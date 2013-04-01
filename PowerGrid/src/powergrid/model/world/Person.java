package powergrid.model.world;

import java.util.ArrayList;
import java.util.Objects;
import org.powerbot.game.client.CombatStatus;
import org.powerbot.game.client.CombatStatusData;
import org.powerbot.game.client.LinkedList;
import org.powerbot.game.client.LinkedListNode;
import org.powerbot.game.client.RSAnimator;
import org.powerbot.game.client.RSMessageData;
import org.powerbot.game.client.RSNPC;
import powergrid.model.Point;

public class Person {
    private RSNPC rsnpc;
    private Point position;
    
    public Person(RSNPC rsnpc){
        assert rsnpc != null;
        this.rsnpc = rsnpc;
    }

    public RSNPC getRSNPC() {
        return rsnpc;
    }   

    public Point getPosition() {
        return position;
    }

    public void setPosition(Point position) {
        assert position != null;
        this.position = position;
    }
    
    public int getID() {
        return getRSNPC().getRSNPCDef().getID();
    }
    
    public int getLevel() {
        return getRSNPC().getRSNPCDef().getLevel();
    }
    
    public String getName() {
        return getRSNPC().getRSNPCDef().getName();
    }
    
    public String[] getActions() {
        return getRSNPC().getRSNPCDef().getActions();
    }
    
    public int getPrayerIcon() {
        return getRSNPC().getRSNPCDef().getPrayerIcon();
    }
    
    public int getMoveSpeed() {
        return getRSNPC().isMoving();
    }
    
    public boolean isMoving() {
        return getMoveSpeed() != 0;
    }
    
    public int getAnimation() {
        RSAnimator anim = getRSNPC().getAnimation();
        return (anim == null ? -1 : anim.getSequence().getID());
    }
    
    public String getMessage() {
        RSMessageData mData = getRSNPC().getMessageData();
        return (mData == null ? null : mData.getMessage());
    }
    
    public CombatStatusData[] getCombatStatusData() {
        LinkedList list = getRSNPC().getCombatStatusList();
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
        if (other instanceof Person) {
            Person that = (Person) other;
            return this.getPosition().equals(that.getPosition()) &&
                    Objects.equals(this.getRSNPC(), that.getRSNPC());
        }
        return false;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 67 * hash + Objects.hashCode(this.rsnpc);
        hash = 67 * hash + Objects.hashCode(this.position);
        return hash;
    }
    
    @Override public String toString() {
        StringBuilder sb = new StringBuilder("Person: ");
        sb.append(getName()).append(" (Level ").append(getLevel()).append(")");
        return sb.toString();
    }
}
