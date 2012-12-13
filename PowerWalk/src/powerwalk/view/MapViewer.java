package powerwalk.view;

import java.awt.BorderLayout;
import java.awt.Canvas;
import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import powerwalk.Bot;
import powerwalk.model.Grid;
import powerwalk.model.Point;
import powerwalk.model.world.Wall;

/**
 * Canvas that the WorldMap is printed on to show the mapped areas in the Grid
 * @author P.Kramer
 */
public class MapViewer extends Canvas {
    
    /**
     * Shows a MapViewer in a new JFrame
     */
    public static void showMapViewer() {
        JFrame f = new JFrame("Map View");
        MapViewer viewer = new MapViewer();
        JScrollPane sp = new JScrollPane(viewer);
        f.setLayout(new BorderLayout());
        f.add(sp);
        f.setSize(640,480);
        sp.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        sp.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        
        f.setVisible(true);
    }
    
    /**
     * Creates a new Canvas that the World Map will be drawn on
     */
    public MapViewer() {
        super();
        setSize(4000, 4000);
    }
    
    /**
     * paints the content of this MapViewer
     * @param g the Graphics-object used to draw on this Canvas
     */
    @Override public void paint(Graphics g) {
        if (g == null) return;
        Grid grid = Bot.getBot().getWorldMap();
        for (int x=0;x<4000;x++) {
            for (int y=0;y<4000;y++) {
                if (grid.get(new Point(x,y)) instanceof Wall)
                    g.fillRect(x, y, 1, 1);
            }
        }
    }
}
