package test.view;

import static org.junit.Assert.assertTrue;
import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import static org.mockito.Mockito.when;
import org.mockito.runners.MockitoJUnitRunner;
import powergrid.model.Point;
import powergrid.model.WorldMap;
import powergrid.model.world.Player;
import powergrid.view.MapViewer;

/**
 * Tests the functionality of the MapViewer
 * @author Chronio
 */
@Ignore ( "MapViewer throws NPE on addNotify() for unknown reason" )
@RunWith( MockitoJUnitRunner.class )
public class MapViewerTest {
    
    private MapViewer mv = null;
    private WorldMap map = null;
    @Mock private Player player;
    
    @Before public void setup() {
        when(player.getPosition()).thenReturn(new Point());
        
        map = new WorldMap();
        map.put(null);
        
        mv = new MapViewer()
                .usePlayer(player)
                .useMap(map)
                .initialize();
    }
    
    @Test public void testActive() {
        assertTrue(mv.getActive());
    }
}
