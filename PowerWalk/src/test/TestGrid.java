package test;

import powerwalk.model.GameObject;
import powerwalk.model.Grid;
import powerwalk.model.Point;

public class TestGrid {
    
    /*
     * Test class for the Grid class.
     * The Grid passed this Test completely.
     */
    
    public static Grid g = new Grid();
    
    public static void main(String[] args) {
        //get from empty grid
        System.out.print("g.get() non-existing value\t\t");
        GameObject o = g.get(new Point(3,6,9));
        if (o == null) {
            System.out.println("succes");
        } else {
            System.out.println("failure: object was " + o);
        }
        
        //store in Grid
        System.out.print("g.get()/g.set() single value\t\t");
        o = new GameObject(4,7,8,46645);
        g.set(o.getPosition(), o);
        o = g.get(new Point(4,7,8));
        if (o == null) System.out.println("failure: object was null");
        else if (o.getRawNumber() == 46645) {
            System.out.println("succes");
        } else System.out.println("failure: number was " + o.getRawNumber());
        
        // delete from Grid
        System.out.print("g.delete() single value\t\t\t");
        o = new GameObject(5,6,9,77644);
        g.set(o.getPosition(), o);
        if (g.get(o.getPosition()) == null) System.out.println("failure: not stored");
        else {
            g.delete(o.getPosition());
            o = g.get(new Point(5,6,9));
            if (o == null) {
                System.out.println("succes");
            } else System.out.println("failure: object was " + o);
        }
        
        // delete from non-existing field
        System.out.print("g.delete() non-existing value\t\t");
        try {
            o = g.delete(new Point(24,36,85));
            if (o == null) {
                System.out.println("succes");
            } else System.out.println("failure: object was " + o);
        } catch (NullPointerException | ArrayIndexOutOfBoundsException e) {
            System.out.println("exception: " + e);
        }
        
        // get / set with offset
        System.out.print("g.setOffset() single value\t\t");
        g.setOffset(new Point(10,11,12));
        o = new GameObject(3,4,15,7667);
        g.set(o.getPosition(),o);
        o = g.get(new Point(3,4,15));
        if (o == null) {
            System.out.println("failure: object was null");
        } else if (o.getRawNumber() == 7667) {
            System.out.println("succes");
        } else System.out.println("failure: object was " + o);
    }
}
