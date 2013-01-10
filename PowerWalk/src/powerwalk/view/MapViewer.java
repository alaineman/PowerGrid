package powerwalk.view;

import java.awt.*;
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
        f.setSize(640,480);
        sp.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        sp.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        
        f.setVisible(true);
    }
    
    private Grid theMap = null;
    
    public static MapViewer theMapViewer = null;
    
    private int scale = 3;                                  // the scale factor
    private Rectangle r = new Rectangle(3000,3200,480,320); // The Area to view (x,y,width,height)
    
    /**
     * Creates a new Canvas that the World Map will be drawn on
     */
    public MapViewer() {
        super();
        theMap = Bot.getBot().getWorldMap();
        setSize(r.width*scale, r.height*scale);
    }
    
    /**
     * paints the content of this MapViewer.
     * <p>The following color mapping is used:</p>
     * <pre>
     *    Unexplored or empty: WHITE
     *    !canReach() matches: DARK_GRAY
     *    detected Walls:      BLACK
     *    Interactions:        YELLOW
     *    "Paved" tiles:       LIGHT_GRAY
     * </pre>
     * Note: Paved tiles are unknown tiles, but which have been marked as walkable
     * @param g the Graphics-object used to draw on this Canvas
     */
    @Override public void paint(Graphics g) {
        if (g == null) return;
        for (int x=r.x;x<r.x+r.width;x++) {
            for (int y=r.y;y<r.y+r.height;y++) {
                GameObject go = theMap.get(new Point(x,y));
                
                if (go == null)                         // unexplored (WHITE)
                    g.setColor(Color.WHITE);
                else if (go.getRawNumber() == 0)       // "paved" tiles (LIGHT_GRAY)
                    g.setColor(Color.LIGHT_GRAY);
                else if (go.getRawNumber() < 0)       // overwritten Collisions / Walls (DARK_GRAY)
                    g.setColor(Color.DARK_GRAY);
                else if (go instanceof Collision)       // PowerWalk Collision tiles (BLACK)
                    g.setColor(Color.BLACK);
                else if (go instanceof Interactable)    // PowerWalk Interaction Tiles (YELLOW)
                    g.setColor(Color.YELLOW);
                else
                    g.setColor(Color.WHITE);       // Uncategorized Tiles (WHITE)
                
                
                g.fillRect(scale*(x-r.x),scale*(r.height-(y-r.y)),scale,scale);
            }
        }
        try {
            Point p = Bot.getBot().getPosition();
            if (p.x > r.x && p.x < r.x+r.width &&
                p.y > r.x && p.y < r.y+r.height) {
                g.setColor(Color.red);
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
