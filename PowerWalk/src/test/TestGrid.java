package test;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import powerwalk.Bot;
import powerwalk.control.ToolBox;
import powerwalk.model.GameObject;
import powerwalk.model.Grid;
import powerwalk.model.Point;
import powerwalk.model.XMLNode;
import powerwalk.model.world.Wall;

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
        
        // size() for empty
        System.out.print("g.size() is empty\t\t\t");
        if (g.size() == 0) System.out.println("succes");
        else System.out.println("failure: size was " + g.size());
        
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
        g.setOffset(new Point(0,0,0));
        
        // size() after set
        System.out.print("size() after set\t\t\t");
        int size = g.size();
        o = new GameObject(3,8,4,23735);
        g.set(o.getPosition(),o);
        if (g.size() == size+1) System.out.println("succes");
        else System.out.println("failure: was " + g.size());
        
        // size() after delete
        System.out.print("size() after add\t\t\t");
        size = g.size();
        g.delete(o.getPosition());
        if (g.size() == size-1) System.out.println("succes");
        else System.out.println("failure: was " + g.size());
        
        
        Grid worldmap = Bot.getBot().getWorldMap();
        ArrayList<Wall> walls = TestPathFinder.createMaze();
        for (Wall w : walls) {
            worldmap.set(w.getPosition(),w);
        }
        XMLNode rootNode = worldmap.getXMLTree();
        try (FileWriter writer = new FileWriter(new File("worldmap.xml"))) {
            writer.write(rootNode.toString()); // save to xml file
        } catch (IOException iox) {}
        
        
        
        System.out.print("save/load/equals\t\t\t");
        try {
            FileInputStream in = new FileInputStream(new File("worldmap.xml"));
            XMLNode recoveredTree = ToolBox.getXMLTree(in); // get from xml file
            Grid recoveredGrid = new Grid();
            recoveredGrid.fillFromXML(recoveredTree); // store in new Grid
            recoveredTree = recoveredGrid.getXMLTree(); // rebuild from recovered Tree
            if (recoveredTree.hashCode() == rootNode.hashCode()) {
                if (recoveredTree.equals(rootNode)) {
                    System.out.println("succes");
                } else {
                    System.out.println("succes; equals() failed");
                }
            } else {
                if (recoveredTree.equals(rootNode)) {
                    System.out.println("succes; hashCode failed");
                } else {
                    System.out.println("failure: not equals()");
                }
            }
        } catch (FileNotFoundException e404) {
            System.out.println("failure: " + e404);
        }
        
    }
}
