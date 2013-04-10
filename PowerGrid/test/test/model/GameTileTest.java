package test.model;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import static org.mockito.Mockito.*;
import org.mockito.runners.MockitoJUnitRunner;
import org.powerbot.game.client.RSGround;
import org.powerbot.game.client.RSObject;
import powergrid.model.world.GameTile;
import powergrid.model.Point;
import powergrid.model.world.Wall;

@RunWith(MockitoJUnitRunner.class)
public class GameTileTest {
    public GameTile go;
    
    @Mock public RSGround mockedGround;
    @Mock public RSObject mockedBoundary;
    @Mock public RSObject mockedDecoration;
    
    @Before public void setup() {
        go = new GameTile(new Point(3,4),mockedGround,Wall.EAST | Wall.NORTH);
        when(mockedGround.getBoundary1()).thenReturn(null);
        when(mockedGround.getBoundary2()).thenReturn(mockedBoundary);
        when(mockedGround.getFloorDecoration()).thenReturn(null);
        when(mockedGround.getWallDecoration1()).thenReturn(null);
        when(mockedGround.getWallDecoration2()).thenReturn(mockedDecoration);
        
        when(mockedBoundary.getId()).thenReturn(25575);
        when(mockedDecoration.getId()).thenReturn(47746);
    }
    
    @Test public void testGetObjects() {
        assertArrayEquals(new RSObject[] {mockedBoundary, mockedDecoration},go.objects());
    }
    
    @Test public void testRawValues() {
        assertArrayEquals(new int[] {25575,47746},go.rawValues());
    }
    
    @Test public void testRawValuesEmpty() {
        when(mockedGround.getBoundary2()).thenReturn(null);
        when(mockedGround.getWallDecoration2()).thenReturn(null);
        assertArrayEquals(new int[0],go.rawValues());
    }
    
    @Test public void testContainsRawValueTrue() {
        assertTrue(go.containsRawValue(47746));
    }
    
    @Test public void testContainsRawValueFalse() {
        assertFalse(go.containsRawValue(20056));
    }
    
    @Test public void testGetBoundary() {
        assertEquals(25575,go.getBoundary());
    }
    
    @Test public void testGetNonExistingBoundary() {
        when(mockedGround.getBoundary2()).thenReturn(null);
        assertEquals(-1,go.getBoundary());
    }
    
    @Test public void testEqualsSelf() {
        assertEquals(go,go);
    }
    
    @Test public void testEqualsOtherFalse() {
        assertFalse(go.equals(new GameTile(new Point(6,4),mockedGround,0)));
    }
    
    @Test public void testContainsWallTrue() {
        assertTrue(go.containsWall(Wall.EAST));
    }
    
    @Test public void testContainsWallFalse() {
        assertFalse(go.containsWall(Wall.SOUTH));
    }
}
