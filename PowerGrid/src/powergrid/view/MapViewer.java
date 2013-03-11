package powergrid.view;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferStrategy;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.HashMap;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import powergrid.PowerGrid;
import powergrid.control.XMLParser;
import powergrid.model.GameObject;
import powergrid.model.Point;
import powergrid.model.WorldMap;
import powergrid.model.XMLElement;
import powergrid.model.interact.Interactable;
import powergrid.model.world.Wall;
import powergrid.tasks.TravelTask;

/**
 * Canvas that the WorldMap is printed on to show the mapped areas in the Grid.
 * @author Chronio
 */
public class MapViewer extends Canvas implements ActionListener {
    
    /**
     * Shows a MapViewer in a new JFrame
     */
    public static void showMapViewer() {
        if (theMapViewer == null)
            theMapViewer = new MapViewer();
        theMapViewer.actionPerformed(null);
    }
    
    private static WorldMap theMap = null;
    
    public static MapViewer theMapViewer = null;
    
    // the default drawing colors
    private static final HashMap<String,Color> defaults = new HashMap<>(12);
    static { 
        defaults.put("background",  Color.LIGHT_GRAY);
        defaults.put("wall",        Color.DARK_GRAY);
        defaults.put("water",       new Color(22,53,160));
        defaults.put("empty",       Color.WHITE);
        defaults.put("fence",       new Color(147,111,36));
        defaults.put("interaction", Color.RED);
        defaults.put("player",      Color.GREEN);
    };
    
    // custom drawing colors
    private static HashMap<String,Color> custom = new HashMap<>(12);
    
    public static void setCustomColor(String element, Color color) {
        if (color == null || element == null) 
            throw new IllegalArgumentException("Neither the element nor the color is allowed to be null");
        if (!defaults.containsKey(element)) {
            String values = "";
            for (String key : defaults.keySet()) {
                values += ", " + key;
            }
            throw new IllegalArgumentException("Not a valid argument, valid arguments are: " + values.substring(2));
        }
            
        
        custom.put(element, color);
    }
    
    public static void restoreDefault(String element) {
        custom.remove(element);
    }
    
    public static boolean hasCustomColor(String element) {
        return custom.containsKey(element);
    }
    
    public static Color getUsedColor(String element) {
        if (element == null)
            throw new IllegalArgumentException("The element is not allowed to be null");
        if (!defaults.containsKey(element))
            throw new IllegalArgumentException("Not a valid argument");
        Color c = custom.get(element);
        if (c == null)
            c = defaults.get(element);
        return c;
    }
    
    private static int scale = 3;                                  // the scale factor
    private static Rectangle r = new Rectangle(2850,3050,640,480); // The Area to view (x,y,width,height)
    private boolean buffersReady = false;
    private boolean holding = false;
    
    /**
     * Creates a new Canvas that the World Map will be drawn on
     */
    public MapViewer() {
        super();
        theMap = PowerGrid.MAPPER.getWorldMap();
        setSize(r.width*scale, r.height*scale);
    }
    
    public void setupBufferStrategyAndRepaint() {
        if (!buffersReady) {
            createBufferStrategy(2);
            setIgnoreRepaint(true);
            (new Thread("MapRenderer") {
                @SuppressWarnings("SleepWhileInLoop")
                @Override public void run() {
                    BufferStrategy bs = getBufferStrategy();
                    while (true) {
                        if (holding) {
                            try { Thread.sleep(50); } 
                            catch (InterruptedException e) {}
                        } else {
                            Graphics g = bs.getDrawGraphics();
                            paint(g);
                            g.dispose();
                            bs.show();
                        }
                    }
                }
            }).start();
        }
    }
    
    /**
     * paints the content of this MapViewer.
     * @param g the Graphics-object used to draw on this Canvas
     */
    @Override public void paint(Graphics g) {
        HashMap<String,Color> current = new HashMap<>(12);
        for (String s : defaults.keySet()) {
            current.put(s, getUsedColor(s));
        }
        if (g == null) return;
        for (int x=r.x;x<r.x+r.width;x++) {
            for (int y=r.y;y<r.y+r.height;y++) {
                GameObject go = theMap.getObject(new Point(x,y));
                Rectangle area = new Rectangle(scale*(x-r.x),scale*(r.height-(y-r.y)),scale,scale); // the rectangle we draw in
                
                if (go == null)
                    g.setColor(current.get("empty"));
                else if (go instanceof Interactable)
                    g.setColor(current.get("interaction"));
                else if (go.getRawNumber() == -5 || go.getRawNumber() == 85)
                    g.setColor(current.get("water"));
                else if (go.getRawNumber() == -3)
                    g.setColor(current.get("fence"));
                else if (go instanceof Wall)
                    g.setColor(current.get("wall"));
                else
                    g.setColor(current.get("background"));
                
                if (go instanceof Wall && scale != 1 && g.getColor().equals(current.get("wall"))) {
                    Wall w = (Wall)go;
                    if (w.isType(Wall.BLOCK))
                        g.fillRect(area.x, area.y, scale, scale);
                    else {
                        g.setColor(current.get("empty"));
                        g.fillRect(area.x, area.y, scale, scale);
                        g.setColor(current.get("wall"));
                        if (w.containsType(Wall.NORTH))
                            g.drawLine(area.x, area.y, area.x+scale-1, area.y);
                        if (w.containsType(Wall.EAST))
                            g.drawLine(area.x+scale-1, area.y, area.x+scale-1, area.y+scale-1);
                        if (w.containsType(Wall.SOUTH))
                            g.drawLine(area.x, area.y+scale-1, area.x+scale-1, area.y+scale-1);
                        if (w.containsType(Wall.WEST))
                            g.drawLine(area.x, area.y, area.x, area.y+scale-1);
                    }
                } else {
                    g.fillRect(area.x,area.y,scale,scale);
                }
            }
        }
        // try to draw the player, if any exists
        try {
            Point p = PowerGrid.BOT.getPosition();
            if (p.x > r.x && p.x < r.x+r.width &&
                p.y > r.x && p.y < r.y+r.height) {
                g.setColor(current.get("player"));
                g.fillRect(scale*(p.x-r.x),scale*(r.height-(p.y-r.y)),scale,scale);
            }
        } catch (NullPointerException p) {}
    }
    
    /**
     * Holds drawing when set to true. Resumes drawing when set to false.
     * <p/>
     * It can be used to hold drawing while updating the world map. This prevents
     * tearing.
     * <p/>
     * @param hold 
     */
    public void hold(boolean hold) {
        holding = hold;
    }
    
    /**
     * Shows the World Map in a separate frame without loading PowerGrid
     * This can be done without RSBot.
     * @param exitOnClose when true, terminates the application when the window is closed
     */
    //FIXME broken because of changes in Mapper.
    public static void showMapViewerStandAlone(boolean exitOnClose) {
        File file = new File("worldmap.xml");
        try (FileInputStream worldMapIn = new FileInputStream(file)) {
            XMLElement worldMap = XMLParser.getXMLTree(worldMapIn);
            //PowerGrid.MAPPER.getWorldMap().fillFromXML(worldMap);
            System.out.println("The World Map was loaded");
        } catch (IOException e) {
            System.out.println("The World Map failed to load from file: " + file.getAbsolutePath());
        }
        showMapViewer();
    }
    
    public static void main(String[] args) {
        showMapViewerStandAlone(true);
    }
    
    @Override public void actionPerformed(ActionEvent ae) {
        JFrame f = new JFrame("Map View");
        JScrollPane sp = new JScrollPane(this);
        f.setLayout(new BorderLayout());
        f.add(sp,"Center");
        f.setSize(r.width*scale + 48,r.height*scale + 48);
        sp.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        sp.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        
        f.setVisible(true);
        setupBufferStrategyAndRepaint();
        addMouseListener(new MouseAdapter() {
            @Override public void mouseReleased(MouseEvent me) {
                if (me.getButton() == MouseEvent.BUTTON1) {
                    // walk to point that was clicked on map
                    // This might or might not work as-is
                    java.awt.Point p = me.getPoint();
                    p.x /= scale;
                    p.y /= scale;
                    p.x += r.x;
                    p.y += r.y;
                    Point dest = new Point(p.x,p.y);
                    PowerGrid.TM.clear();
                    PowerGrid.TM.assignTask(new TravelTask(dest,0));
                }
            }
        });
    }
}
