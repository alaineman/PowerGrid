package test.control;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import static org.mockito.Mockito.*;
import org.mockito.runners.MockitoJUnitRunner;
import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.client.BaseInfo;
import org.powerbot.game.client.Client;
import org.powerbot.game.client.RSGround;
import org.powerbot.game.client.RSGroundData;
import org.powerbot.game.client.RSGroundInfo;
import org.powerbot.game.client.RSInfo;
import org.powerbot.game.client.RSInteractable;
import org.powerbot.game.client.RSInteractableData;
import org.powerbot.game.client.RSInteractableLocation;
import powergrid.control.Mapper;
import powergrid.control.Mapper.MapperThread;
import powergrid.model.Point;
import powergrid.model.structure.WorldMap;
import powergrid.model.world.GameTile;

@RunWith(MockitoJUnitRunner.class)
public class MapperTest {
    
    /** Adapter-style interface that combines the RSGround and RSInteractable interfaces. */
    public interface RSInteractableGround extends RSGround, RSInteractable {}
    
    @Mock public Client mockedClient;
    @Mock public RSInfo mockedRSInfo;
    @Mock public RSGroundInfo mockedRSGroundInfo;
    @Mock public BaseInfo mockedBaseInfo;
    @Mock public RSInteractableData mockedRSInteractableData;
    @Mock public RSInteractableLocation mockedRSInteractableLocation;
    @Mock public RSGroundData mockedRSGroundData;
    @Mock public RSInteractableGround mockedRSGround;
    
    @Mock public WorldMap mockedMap;
    
    public Mapper mapper;
    
    @Before public void setup() {
        when(mockedClient.getRSGroundInfo()).thenReturn(mockedRSInfo);
        when(mockedClient.getPlane()).thenReturn(1);
        
        when(mockedRSInfo.getRSGroundInfo()).thenReturn(mockedRSGroundInfo);
        when(mockedRSInfo.getGroundData()).thenReturn(new RSGroundData[] {null,mockedRSGroundData,null});
        when(mockedRSInfo.getBaseInfo()).thenReturn(mockedBaseInfo);
        
        when(mockedRSGroundInfo.getRSGroundArray()).thenReturn(
                new RSGround[][][] {{{null},{mockedRSGround},{null}}}
                );
        
        when(mockedBaseInfo.getX()).thenReturn(2);
        when(mockedBaseInfo.getY()).thenReturn(4);
        
        when(mockedRSGround.getData()).thenReturn(mockedRSInteractableData);
        
        when(mockedRSInteractableData.getLocation()).thenReturn(mockedRSInteractableLocation);
        
        when(mockedRSInteractableLocation.getX()).thenReturn(0f);
        when(mockedRSInteractableLocation.getY()).thenReturn(0f);
        
        when(mockedRSGroundData.getBlocks()).thenReturn(
                new int[][]{
                    {0                        ,Tile.Flag.OBJECT_BLOCK|Tile.Flag.OBJECT_TILE},
                    {Tile.Flag.WALL_BLOCK_EAST,Tile.Flag.WALL_BLOCK_SOUTH}
                });
        
        mapper = new Mapper(mockedClient).withMap(mockedMap);
    }
    
    @Test public void testIsMappingIdle() {
        assertEquals(false,mapper.isMapping());
    }
    
    @Test public void testMapOnce() {
        mapper.mapOneRound();
        
        verify(mockedMap).put(new GameTile(new Point(2,4,1), mockedRSGround, 0));
        
        verify(mockedMap).put(new GameTile(new Point(3,4,1), null, GameTile.BLOCK));
        verify(mockedMap).put(new GameTile(new Point(2,5,1), null, GameTile.EAST));
        verify(mockedMap).put(new GameTile(new Point(3,5,1), null, GameTile.SOUTH));
    }
    
    @Test public void testEquals() {
        assertTrue(mapper.equals(mapper));
        assertTrue(mapper.equals(new Mapper(mockedClient).withMap(mockedMap)));
        assertFalse(mapper.equals(null));
        assertFalse(mapper.equals(new Mapper()));
    }
    
    @Test public void testCopy() {
        assertTrue(mapper.equals(mapper.copy()));
    }
    
    @Test public void testMapperStartStop() {
        mapper.startMapping();
        assertTrue(mapper.isMapping());
        mapper.stopMapping();
        assertFalse(mapper.isMapping());
    }
    
    @Test public void testMapperThread() {
        MapperThread thread = mapper.new MapperThread(10);
        
        thread.run();
        
        verify(mockedMap).put(new GameTile(new Point(2,4,1), mockedRSGround, 0));        
       
        verify(mockedMap).put(new GameTile(new Point(3,4,1), null, GameTile.BLOCK));
        verify(mockedMap).put(new GameTile(new Point(2,5,1), null, GameTile.EAST));
        verify(mockedMap).put(new GameTile(new Point(3,5,1), null, GameTile.SOUTH));
    }
}
