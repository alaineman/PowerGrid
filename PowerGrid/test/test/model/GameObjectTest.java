package test.model;

import org.junit.Before;
import org.mockito.Mock;
import static org.mockito.Mockito.*;
import org.powerbot.game.client.RSGround;
import org.powerbot.game.client.RSObject;
import powergrid.model.GameObject;
import powergrid.model.Point;
import powergrid.model.world.Wall;

public class GameObjectTest {
    public GameObject go;
    
    @Mock public RSGround mockedGround;
    @Mock public RSObject mockedBoundary;
    @Mock public RSObject mockedDecoration;
    
    @Before public void setup() {
        go = new GameObject(new Point(3,4),mockedGround,Wall.EAST | Wall.NORTH);
        when(mockedGround.getBoundary1()).thenReturn(null);
        when(mockedGround.getBoundary2()).thenReturn(mockedBoundary);
        when(mockedGround.getFloorDecoration()).thenReturn(null);
        when(mockedGround.getWallDecoration1()).thenReturn(null);
        when(mockedGround.getWallDecoration2()).thenReturn(mockedDecoration);
        
        when(mockedBoundary.getId()).thenReturn(25575);
        when(mockedDecoration.getId()).thenReturn(47746);
    }
}
