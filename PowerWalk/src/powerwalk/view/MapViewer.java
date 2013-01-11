package powerwalk.view;

import java.awt.*;
import java.awt.image.BufferStrategy;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import powerwalk.Bot;
import powerwalk.Starter;
import powerwalk.control.XMLToolBox;
import powerwalk.model.Point;
import powerwalk.model.*;
import powerwalk.model.interact.Interactable;

/**
 * Canvas that the WorldMap is printed on to show the mapped areas in the Grid
 * @author Chronio
 */
public class MapViewer extends Canvas {
    
    /**
     * Shows a MapViewer in a new JFrame
     */
    public static void showMapViewer() {
        JFrame f = new JFrame("Map View");
        theMapViewer = new MapViewer();
        JScrollPane sp = new JScrollPane(theMapViewer);
        f.setLayout(new BorderLayout());
        f.add(sp,"Center");
        f.setSize(r.width*scale + 48,r.height*scale + 48);
        sp.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        sp.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        
        f.setVisible(true);
        theMapViewer.setupBufferStrategyAndRepaint();
    }
    
    private static Grid theMap = null;
    
    public static MapViewer theMapViewer = null;
    
    // the drawing colors; they can be changed, so personal color schemes is a 
    // possible feature
    public static Color background = Color.LIGHT_GRAY;
    public static Color walls = Color.DARK_GRAY;
    public static Color water = new Color(22,53,160);
    public static Color empty = Color.WHITE;
    public static Color fences = new Color(147,111,36);
    public static Color interactions = Color.RED;
    public static Color player = Color.GREEN;
    
    private static int scale = 2;                                  // the scale factor
    private static Rectangle r = new Rectangle(2850,3050,640,480); // The Area to view (x,y,width,height)
    private boolean buffersReady = false;
    /**
     * Creates a new Canvas that the World Map will be drawn on
     */
    public MapViewer() {
        super();
        theMap = Bot.getBot().getWorldMap();
        setSize(r.width*scale, r.height*scale);
    }
    
    public void setupBufferStrategyAndRepaint() {
        if (!buffersReady) {
            createBufferStrategy(2);
            setIgnoreRepaint(true);
            (new Thread("MapRenderer") {
                @Override public void run() {
                    BufferStrategy bs = getBufferStrategy();
                    while (!false) {
                        Graphics g = bs.getDrawGraphics();
                        paint(g);
                        g.dispose();
                        bs.show();
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
        if (g == null) return;
        for (int x=r.x;x<r.x+r.width;x++) {
            for (int y=r.y;y<r.y+r.height;y++) {
                GameObject go = theMap.get(new Point(x,y));
                
                if (go == null)
                    g.setColor(empty);
                else if (go instanceof Interactable)
                    g.setColor(interactions);
                else if (go.getRawNumber() == 0)
                    g.setColor(background);
                else if (go.getRawNumber() == -1 || go.getRawNumber() == 85)
                    g.setColor(water);
                //else if (go.getRawNumber() == -2)
                //    g.setColor(walls);
                else if (go.getRawNumber() == -3)
                    g.setColor(fences);
                else if (go instanceof Collision)
                    g.setColor(walls);
                else
                    g.setColor(empty);
                
                g.fillRect(scale*(x-r.x),scale*(r.height-(y-r.y)),scale,scale);
            }
        }
        // try to draw the player, if any exists
        try {
            Point p = Bot.getBot().getPosition();
            if (p.x > r.x && p.x < r.x+r.width &&
                p.y > r.x && p.y < r.y+r.height) {
                g.setColor(player);
                g.fillRect(scale*(p.x-r.x),scale*(r.height-(p.y-r.y)),scale,scale);
            }
        } catch (NullPointerException p) {}
    }
    
    /**
     * Shows the World Map in a separate frame without loading the entire plug-in.
     * This can be done without RSBot.
     * @param exitOnClose when true, terminates the application when the window is closed
     */
    public static void showMapViewerStandAlone(boolean exitOnClose) {
        String path = System.getProperty("user.home") + "\\Appdata\\Local\\Temp\\PowerWalk\\";
        File file = new File(path + Starter.worldMapFile);
        try (FileInputStream worldMapIn = new FileInputStream(file)) {
            XMLNode worldMap = XMLToolBox.getXMLTree(worldMapIn);
            Bot.getBot().getWorldMap().fillFromXML(worldMap);
            System.out.println("The World Map was loaded");
        } catch (IOException e) {
            System.out.println("The World Map failed to load from file: " + file.getAbsolutePath());
        }
        showMapViewer();
    }
    
    public static void main(String[] args) {
        showMapViewerStandAlone(true);
    }
}
