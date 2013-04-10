package powergrid.view;

import java.awt.*;
import java.awt.image.BufferStrategy;
import java.util.HashMap;
import powergrid.model.Point;
import powergrid.model.structure.WorldMap;
import powergrid.model.world.GameTile;
import powergrid.model.world.player.Player;
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
    private MapRenderer renderer;
    private Player player;
    
    // TODO improve render options
    
    private int scale = 1;
    private Rectangle r = new Rectangle(1024,1024,1024,720);
    private volatile boolean active = false;
    private volatile boolean holding = false;
    private boolean centerToPlayer = false;
    
    /**
     * Creates a new MapViewer.
     */
    public MapViewer() {
        theMap = null;
        renderer = new MapRenderer();
        colors = new HashMap<>();
        player = null;
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
     * @return the WorldMap that is drawn
     */
    public WorldMap getMap() {
        return theMap;
    }
    
    /**
     * Sets the Player to draw. 
     * <p/>
     * The provided Player can be null, in which case no Player will be drawn.
     * @param p the Player to draw, or null to draw no Player
     * @return itself for fluency
     */
    public MapViewer usePlayer(Player p) {
        player = p;
        return this;
    }
    
    /**
     * @return the Player that is drawn on the map
     */
    public Player getPlayer() {
        return player;
    }
    
    /**
     * Sets whether to continuously center the map at the Player's position.
     * <p/>
     * This setting is ignored when no Player has been set.
     * @param ctp true to continuously update the displayed region
     */
    public void setAutoCenter(boolean ctp) {
        centerToPlayer = ctp;
    }
    
    /**
     * @return whether the map automatically centers at the player's position.
     */
    public boolean getAutoCenter() {
        return centerToPlayer;
    }
    
    /**
     * @return the MapRenderer instance used for scheduling rendering.
     */
    public MapRenderer getRenderer() {
        return renderer;
    }
    
    /**
     * Sets the area to draw.
     * <p/>
     * Tiles outside of this area are ignored.
     * @param r the area to draw
     */
    public void setArea(Rectangle r) {
        this.r = new Rectangle(r);
    }
    
    /**
     * @return the area this MapViewer shows.
     */
    public Rectangle getArea() {
        return new Rectangle(r);
    }
    
    /**
     * Sets the scale to use for drawing.
     * <p/>
     * The scale represents the length of one GameTile in pixels. 
     * This value must be positive.
     * <p/>
     * @param scale the scale to use
     */
    public void setScale(int scale) {
        if (scale <= 0) {
            throw new IllegalArgumentException("Scale mst be > 0");
        }
        this.scale = scale;
    }
    
    /**
     * @return the scale used for drawing
     */
    public int getScale() {
        return scale;
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
     * @return whether to hold drawing
     */
    public boolean getHold() {
        return holding;
    }
    
    /**
     * Holds drawing when set to true. Resumes drawing when set to false.
     * <p/>
     * It can be used to hold drawing while updating the world map. This 
     * prevents synchronization issues.
     * <p/>
     * @param hold whether to hold drawing
     */
    public void setHold(boolean hold) {
        holding = hold;
    }
    
    /**
     * Returns whether this MapViewer is active.
     * <p/>
     * The MapViewer is considered active when the initialize method has been 
     * called, but the disableRepaint method has not been called.
     * <p/>
     * @return whether this MapViewer is active
     */
    public boolean getActive() {
        return active;
    }
    
    /**
     * initializes the Canvas and starts the MapRenderer.
     * <p/>
     * A WorldMap should be set using the <code>useMap(WorldMap)</code> method
     * before calling this method.
     * @return itself for fluency
     */
    public MapViewer initialize() { 
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
        addNotify();
        createBufferStrategy(2);
        setIgnoreRepaint(true);
        
        active = true;
        EventQueue.invokeLater(renderer);
        
        return this;
    }

    /**
     * @return if this Canvas is painted using double buffering, which is true.
     */
    @Override
    public boolean isDoubleBuffered() {
        return true;
    }
    
    /**
     * Stops the repainting of the Canvas.
     * <p/>
     * When this method is called once, consecutive calls of this method 
     * do nothing. Also, paint method calls are ignored.
     * <p/>
     * When this method returns, a repaint might still be in progress. However,
     * no more new repaints are started and the MapRenderer is stopped once the
     * repaint is done.
     * <p/>
     * Windows that contain this Canvas should call this method when they 
     * are disposed to ensure the Renderer is stopped gracefully.
     */
    public void disableRepaint() {
        active = false;
    }
    
    /**
     * Paints the contents of the WorldMap on the Canvas.
     * @param g the Graphics-object used to draw on the Canvas
     */
    @Override public void paint(Graphics g) {
        assert g != null : "Invalid draw graphics provided";
        if (!active) {
            return;
        }
        for (int x=r.x;x<r.x+r.width;x++) {
            for (int y=r.y;y<r.y+r.height;y++) {
                GameTile tile = theMap.get(new Point(x,y));
                
                // The position of this GameTile on the map.
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
        if (c != null && player != null) {
            Point p = player.getPosition();
            // Check if player is in range
            if (p.x > r.x && p.x < r.x+r.width &&
                p.y > r.x && p.y < r.y+r.height) {
                g.setColor(c);
                g.fillRect(
                        scale*(p.x-r.x),
                        scale*(r.height-(p.y-r.y)),
                        scale,
                        scale);
            }
        }
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
            if (getHold()) {
                Task.sleep(50);
            } else {
                Graphics g = bs.getDrawGraphics();
                paint(g);
                g.dispose();
                bs.show();
            }
            if (active) {
                // schedule the repaint on the AWT EventQueue
                EventQueue.invokeLater(this);
            }
        }
        
    }
}
