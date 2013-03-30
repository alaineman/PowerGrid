package test.control.factory;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import static org.mockito.Mockito.*;
import org.mockito.runners.MockitoJUnitRunner;
import org.powerbot.game.client.RSGround;
import powergrid.control.TileFactory;
import powergrid.control.factory.TypeFactory;
import powergrid.model.Point;
import powergrid.model.rsbot.RSGroundImpl;

@RunWith(MockitoJUnitRunner.class)
public class TileFactoryTest {
    
    private TileFactory tf;
    
    @Mock private TypeFactory mockedSimpleFactory;
    @Mock private TypeFactory mockedFancyFactory;
    
    @Before public void setup() {
        tf = new TileFactory();
        
        when(mockedSimpleFactory.accept(any(Point.class), any(RSGround.class), 
                anyInt())).thenReturn(true);
        when(mockedFancyFactory.accept(eq(new Point(2,2)), any(RSGround.class), 
                anyInt())).thenReturn(true);
        when(mockedSimpleFactory.compareTo(mockedFancyFactory)).thenReturn(-1);
        when(mockedFancyFactory.compareTo(mockedSimpleFactory)).thenReturn(1);
    }
    
    @Test public void testAddRemoveFactory() {
        assertTrue(tf.addFactory(mockedSimpleFactory));
        assertEquals(mockedSimpleFactory,tf.removeFactory(mockedSimpleFactory));
    }
    
    @Test public void testRemoveNonExisting() {
        tf.addFactory(mockedSimpleFactory);
        assertNull(tf.removeFactory(mockedFancyFactory));
    }
    
    @Test public void testGetFactory() {
        tf.addFactory(mockedSimpleFactory);
        assertEquals(mockedSimpleFactory,tf.getFactory(new Point(3,3), 
                new RSGroundImpl(), 0));
    }
    
    @Test public void testGetFactoryWithTwoFactories() {
        tf.addFactory(mockedFancyFactory);
        tf.addFactory(mockedSimpleFactory);
        assertEquals(mockedSimpleFactory,tf.getFactory(new Point(3,3),
                new RSGroundImpl(), 0));
        assertEquals(mockedFancyFactory, tf.getFactory(new Point(2,2),
                new RSGroundImpl(), 0));
    }
}
