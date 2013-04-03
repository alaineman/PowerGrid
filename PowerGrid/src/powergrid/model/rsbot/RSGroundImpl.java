package powergrid.model.rsbot;

import org.powerbot.game.client.RSAnimableNode;
import org.powerbot.game.client.RSGround;
import org.powerbot.game.client.RSItemPile;
import org.powerbot.game.client.RSObject;

/**
 * Minimal implementation class for RSGround.
 * @author Chronio
 */
public class RSGroundImpl implements RSGround {

    private RSAnimableNode anim;
    private RSObject bound1,bound2,wall1,wall2,floor;
    private RSItemPile items;

    public RSGroundImpl() {}
    
    public RSGroundImpl(int rawvalue) {
        bound1 = new RSObjectImpl(rawvalue,null);
    }
    
    public RSGroundImpl(RSGround base) {
        assert base != null;
        anim = base.getRSAnimableList();
        bound1 = base.getBoundary1();
        bound2 = base.getBoundary2();
        floor = base.getFloorDecoration();
        wall1 = base.getWallDecoration1();
        wall2 = base.getWallDecoration2();
    }
    
    public RSGroundImpl(RSAnimableNode anim, RSObject bound1, RSObject bound2,
            RSObject wall1, RSObject wall2, RSObject floor, RSItemPile items) {
        this.anim = anim;
        this.bound1 = bound1;
        this.bound2 = bound2;
        this.wall1 = wall1;
        this.wall2 = wall2;
        this.floor = floor;
        this.items = items;
    }
    
    @Override
    public RSAnimableNode getRSAnimableList() {
        return anim;
    }

    @Override
    public RSObject getBoundary1() {
        return bound1;
    }

    @Override
    public RSObject getBoundary2() {
        return bound2;
    }

    @Override
    public RSObject getWallDecoration1() {
        return wall1;
    }

    @Override
    public RSObject getWallDecoration2() {
        return wall2;
    }

    @Override
    public RSObject getFloorDecoration() {
        return floor;
    }

    @Override
    public RSItemPile getRSItemPile() {
        return items;
    }
    
}
