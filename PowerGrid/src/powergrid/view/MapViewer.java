package powergrid.view;

import java.awt.*;
import java.awt.image.BufferStrategy;
import java.util.HashMap;
import powergrid.PowerGrid;
import powergrid.model.GameTile;
import powergrid.model.Point;
import powergrid.model.WorldMap;
import powergrid.model.interact.Interactable;
import powergrid.model.world.Wall;
import powergrid.task.Task;

/**
 * Canvas that shows the WorldMap as an actual map for reference.
 * <p/>
 * Clicking a Tile on the WorldMap will offer a TravelTask to the clicked Point
 * to the Task Queue.
 * @author Chronio
 */
public class MapViewer extends Canvas {
    
    /** The index representing the background of the map. */
    public static final int BACKGROUND = 0;
    /** The index representing walls on the map. */
    public static final int WALL = 1;
    /** The index representing water on the map. */
    public static final int WATER = 2;
    /** The index representing empty tiles on the map. */
    public static final int EMPTY = 3;
    /** The index representing fences on the map. */
    public static final int FENCE = 4;
    /** The index representing interaction objects on the map. */
    public static final int INTERACTION = 5;
    /** The index representing the position of the player on the map. */
    public static final int PLAYER = 6;
    
    
    private WorldMap theMap;
    private HashMap<Integer,Color> colors;
    private Runnable renderer;
    
    // TODO improve render options
    private int scale = 3;
    private Rectangle r = new Rectangle(2850,3050,640,480);
    private boolean holding = false;
    
    /**
     * Creates a new MapViewer.
     */
    public MapViewer() {
        theMap = null;
        renderer = new MapRenderer();
        colors = new HashMap<>(16);
    }
    
    /**
     * Sets the worldmap to use.
     * <p/>
     * the provided WorldMap should not be null.
     * @param map the worldmap to use
     * @return itself for fluency
     */
    public MapViewer useMap(WorldMap map) {
        assert map != null;
        theMap = map;
        return this;
    }
    
    /**
     * initializes the Canvas.
     * <p/>
     * A WorldMap should be set using the <code>useMap(WorldMap)</code> method
     * before calling this method.
     */
    public void initialize() { 
        assert theMap != null : "Map is not set";
        // set the default drawing colors
        colors.put(BACKGROUND,  Color.LIGHT_GRAY);
        colors.put(WALL,        Color.DARK_GRAY);
        colors.put(WATER,       new Color(22,53,160));
        colors.put(EMPTY,       Color.WHITE);
        colors.put(FENCE,       new Color(147,111,36));
        colors.put(INTERACTION, Color.RED);
        colors.put(PLAYER,      Color.GREEN);
        
        // Set up the scheduled repaint.
        createBufferStrategy(2);
        setIgnoreRepaint(true);
        EventQueue.invokeLater(renderer);
    }
    
    /**
     * @param element the element to look up
     * @return the Color used for the specified element
     */
    public Color getColor(int element) {
        return colors.get(element);
    }
    
    /**
     * Sets the drawing Color for the specified element.
     * <p/>
     * If the color is null, the element will not be drawn.
     * <p/>
     * @param element the element to set
     * @param color the Color to use for the specified element.
     * @return the previously used Color for the specified element.
     */
    public Color setColor(int element, Color color) {
        return colors.put(element, color);
    }
    
    /**
     * Paints the contents of the WorldMap on the Canvas.
     * @param g the Graphics-object used to draw on the Canvas
     */
    @Override public void paint(Graphics g) {
        assert g != null : "Invalid draw graphics provided";
        for (int x=r.x;x<r.x+r.width;x++) {
            for (int y=r.y;y<r.y+r.height;y++) {
                GameTile tile = theMap.get(new Point(x,y));
                
                // The Rectangle we draw in
                Point position = new Point(
                        scale*(x-r.x),
                        scale*(r.height-(y-r.y)));
                
                // we only draw the edges of walls to give the map a more 
                // natural look. This only works when the scale > 1.
                if (tile instanceof Wall && scale > 1) {
                    Wall w = (Wall)tile;
                    if (w.isType(Wall.BLOCK))
                        g.fillRect(position.x, position.y, scale, scale);
                    else {
                        g.setColor(getColor(EMPTY));
                        g.fillRect(position.x, position.y, scale, scale);
                        g.setColor(getColor(WALL));
                        if (w.containsType(Wall.NORTH))
                            g.drawLine(position.x, position.y, position.x+scale-1, position.y);
                        if (w.containsType(Wall.EAST))
                            g.drawLine(position.x+scale-1, position.y, position.x+scale-1, position.y+scale-1);
                        if (w.containsType(Wall.SOUTH))
                            g.drawLine(position.x, position.y+scale-1, position.x+scale-1, position.y+scale-1);
                        if (w.containsType(Wall.WEST))
                            g.drawLine(position.x, position.y, position.x, position.y+scale-1);
                    }
                } else {
                    Color c;
                    if (tile == null)
                        c = getColor(EMPTY);
                    else if (tile instanceof Interactable)
                        c = getColor(INTERACTION);
                    else if (tile.getCollisionFlag() == Wall.BLOCK 
                            && tile.getBoundary() == -1)
                        c = getColor(WATER);
                    else if (tile instanceof Wall)
                        c = getColor(WALL);
                    else
                        c = getColor(BACKGROUND);

                    // skip actual drawing if the provided Color is null
                    if (c != null) {
                        g.fillRect(position.x,position.y,scale,scale);
                    }
                }
            }
        }
        // try to draw the player, if any exists
        Color c = getColor(PLAYER);
        if (c != null) {
            try {
                Point p = PowerGrid.PG.bot().getPosition();
                if (p.x > r.x && p.x < r.x+r.width &&
                    p.y > r.x && p.y < r.y+r.height) {
                    g.setColor(c);
                    g.fillRect(
                            scale*(p.x-r.x),
                            scale*(r.height-(p.y-r.y)),
                            scale,
                            scale);
                }
            } catch (NullPointerException npe) {}
        }
    }
    
    
    /**
     * Holds drawing when set to true. Resumes drawing when set to false.
     * <p/>
     * It can be used to hold drawing while updating the world map. This 
     * prevents synchronization issues.
     * <p/>
     * @param hold whether to hold drawing
     */
    public void hold(boolean hold) {
        holding = hold;
    }
    
    /**
     * Runnable that renders the entire map once and then reschedules itself on
     * the AWT Event Thread.
     */
    public class MapRenderer implements Runnable {
        
        /**
         * Issues a single paint on the Canvas, updating all tiles.
         */
        @Override public void run() {
            BufferStrategy bs = getBufferStrategy();
            if (holding) {
                Task.sleep(50);
            } else {
                Graphics g = bs.getDrawGraphics();
                paint(g);
                g.dispose();
                bs.show();
            }
            if (isVisible()) {
                // schedule the repaint on the AWT EventQueue
                EventQueue.invokeLater(this);
            }
        }
        
    }
}
