package test;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import powerwalk.Bot;
import powerwalk.control.PathFinder;
import powerwalk.model.Grid;
import powerwalk.model.OutOfReachException;
import powerwalk.model.Point;
import powerwalk.model.world.Wall;

public class TestPathFinder {
    
    /*
     * Tests the functionality of the PathFinder
     * The PathFinder passed this test
     */
    
    public static void main(String[] args) {
        Grid worldmap = Bot.getBot().getWorldMap();
        ArrayList<Wall> walls = createMaze();
        for (Wall w : walls) {
            worldmap.set(w.getPosition(),w);
        }
        
        // print the maze defined by createMaze()
        for (int x=0;x<16;x++) {
            for (int y=0;y<16;y++) {
                if (Bot.getBot().getWorldMap().get(new Point(x,y,0)) != null) {
                    System.out.print("1");
                } else {
                    System.out.print("0");
                }
            }
            System.out.println();
        }
        
        Point start = new Point(1,8,0);
        Point end = new Point(14,1,0);
        
        // print the path that is calculated by PathFinder.calculatePath(start,end)
        try {
            ArrayList<Point> path = PathFinder.calculatePath(start, end);
            for (Point p : path) {
                System.out.println(p);
            }
        } catch (OutOfReachException e) {
            Logger.getLogger("test").log(Level.SEVERE,"There is no path!",e);
        }
    }
    
    // creates the Maze used for testing
    public static ArrayList<Wall> createMaze() {
        ArrayList<Wall> m = new ArrayList<>();
        
        try (BufferedReader r = new BufferedReader(new FileReader(new File("maze.txt")))) {
            for (int x=0;x<16;x++) {
                String line = r.readLine();
                for (int y=0;y<16;y++) {
                    if (line.charAt(y) == '1') {
                        m.add(new Wall(x,y,0,12994));
                    }
                }
            }
        } catch (IOException iox) {}
        
        return m;
    }
}
