package powerwalk.view;

import java.awt.*;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import powerwalk.Bot;
import powerwalk.Starter;
import powerwalk.control.ToolBox;
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
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        MapViewer viewer = new MapViewer();
        JScrollPane sp = new JScrollPane(viewer);
        f.setLayout(new BorderLayout());
        f.add(sp);
        f.setSize(640,480);
        sp.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        sp.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        
        f.setVisible(true);
    }
    
    private Grid theMap = null;
    
    
    
    private int scale = 3;                                  // the scale factor
    private Rectangle r = new Rectangle(3100,3200,400,300); // The Area to view (x,y,width,height)
    
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
     *    Unexplored:       WHITE
     *    Manually set:     PINK
     *    Collisions:       BLACK
     *    Interactions:     YELLOW
     *    Generic objects:  LIGHT_GRAY
     * </pre>
     * @param g the Graphics-object used to draw on this Canvas
     */
    @Override public void paint(Graphics g) {
        if (g == null) return;
        int nulls = 0;
        for (int x=r.x;x<r.x+r.width;x++) {
            for (int y=r.y;y<r.y+r.height;y++) {
                GameObject go = theMap.get(new Point(x,y));
                
                if (go == null) {                       // unexplored (WHITE)
                    g.setColor(Color.WHITE);
                    nulls++;
                } else if (go.getRawNumber() == -1)     // corrupt or manually overwritten tiles (PINK)
                    g.setColor(Color.PINK);
                else if (go instanceof Collision)       // Collision tiles (BLACK)
                    g.setColor(Color.BLACK);
                else if (go instanceof Interactable)    // Interaction Tiles (YELLOW)
                    g.setColor(Color.YELLOW);
                else
                    g.setColor(Color.LIGHT_GRAY);       // Uncategorized Tiles (LIGHT_GRAY)
                
                
                g.fillRect(scale*(x-r.x),scale*(r.height-(y-r.y)),scale,scale);
            }
        }
        System.out.println("painted canvas with " + (r.width*r.height - nulls) + " tiles");
    }
    
    /**
     * Shows the World Map in a separate frame without loading the entire plug-in.
     * This can be done without RSBot.
     * @param args the command-line arguments, ignored by this method.
     */
    public static void main(String[] args) {
        String path = System.getProperty("user.home") + "\\Appdata\\Local\\Temp\\PowerWalk\\";
        File file = new File(path + Starter.worldMapFile);
        try (FileInputStream worldMapIn = new FileInputStream(file)) {
            XMLNode worldMap = ToolBox.getXMLTree(worldMapIn);
            Bot.getBot().getWorldMap().fillFromXML(worldMap);
            System.out.println("The World Map was loaded");
        } catch (IOException e) {
            System.out.println("The World Map failed to load from file: " + file.getAbsolutePath());
        }
        showMapViewer();
    }
}
