package test.control;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import static org.mockito.Mockito.*;
import org.mockito.runners.MockitoJUnitRunner;
import org.powerbot.game.client.BaseInfo;
import org.powerbot.game.client.Client;
import org.powerbot.game.client.RSGround;
import org.powerbot.game.client.RSGroundInfo;
import org.powerbot.game.client.RSInfo;
import org.powerbot.game.client.RSInteractable;
import powergrid.control.Mapper;
import powergrid.model.WorldMap;

@RunWith(MockitoJUnitRunner.class)
public class MapperTest {
    
    @Mock public Client mockedClient;
    @Mock public RSInfo mockedRSInfo;
    @Mock public RSGroundInfo mockedRSGroundInfo;
    @Mock public BaseInfo mockedBaseInfo;
    
    public RSGround mockedRSGround = mock(RSGround.class, withSettings().extraInterfaces(RSInteractable.class));
    
    @Mock public WorldMap mockedMap;
    
    public Mapper mapper;
    
    @Before public void setup() {
        when(mockedClient.getRSGroundInfo()).thenReturn(mockedRSInfo);
        when(mockedClient.getPlane()).thenReturn(1);
        
        when(mockedRSInfo.getRSGroundInfo()).thenReturn(mockedRSGroundInfo);
        when(mockedRSInfo.getBaseInfo()).thenReturn(mockedBaseInfo);
        
        when(mockedRSGroundInfo.getRSGroundArray()).thenReturn(
                new RSGround[][][] {{{null},{mockedRSGround},{null}}}
                );
        
        when(mockedBaseInfo.getX()).thenReturn(2);
        when(mockedBaseInfo.getY()).thenReturn(4);
        
        mapper = new Mapper(mockedClient).withMap(mockedMap);
    }
    
    @Test public void testIsMappingIdle() {
        assertEquals(false,mapper.isMapping());
    }
    
    @Test public void testMapOnce() {
        mapper.mapOneRound();
    }
}
