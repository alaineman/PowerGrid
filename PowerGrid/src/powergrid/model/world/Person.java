package powergrid.model.world;

import org.powerbot.game.client.RSNPC;
import powergrid.model.Point;

public class Person {
    private RSNPC rsnpc;
    private Point position;
    
    public Person(RSNPC rsnpc){
        this.rsnpc = rsnpc;
    }

    public RSNPC getRsnpc() {
        return rsnpc;
    }   

    public Point getPosition() {
        return position;
    }

    public void setPosition(Point position) {
        this.position = position;
    }
    
    
    
    
    
    
}


