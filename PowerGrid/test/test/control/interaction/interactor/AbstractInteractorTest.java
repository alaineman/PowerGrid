package test.control.interaction.interactor;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import static org.mockito.Matchers.any;
import static org.mockito.Matchers.anyBoolean;
import static org.mockito.Matchers.anyInt;
import org.mockito.Mock;
import static org.mockito.Mockito.CALLS_REAL_METHODS;
import static org.mockito.Mockito.when;
import org.mockito.runners.MockitoJUnitRunner;
import org.powerbot.game.api.wrappers.Locatable;
import org.powerbot.game.api.wrappers.ViewportEntity;
import org.powerbot.game.client.Client;
import powergrid.control.uicontrols.RSInteractor;
import powergrid.model.Point;
import powergrid.model.WorldMap;
import powergrid.model.world.Player;

/**
 * Test class that can be used as a base for Interactor tests.
 * <p/>
 * This class mocks the worldmap, player, RSInteractor, and Client by default a
 * and sets up return values for default method calls
 * @author Patrick
 */
@RunWith(MockitoJUnitRunner.class)
public class AbstractInteractorTest {
    
    @Mock private WorldMap mockedWorldMap;
    @Mock private Player mockedPlayer;
    @Mock private Client mockedClient;
    @Mock private RSInteractor mockedRSInteractor;
    
    /**
     * Stubs the RSInteractor.
     * <p/>
     * Any other Mocks are not stubbed in this method, stub them as needed.
     */
    @Before public void setup() {
        when(mockedRSInteractor.click(any(Locatable.class)))
                .thenReturn(true);
        when(mockedRSInteractor.click(any(ViewportEntity.class)))
                .thenReturn(true);
        when(mockedRSInteractor.click(any(ViewportEntity.class), anyBoolean()))
                .thenReturn(true);
        
        when(mockedRSInteractor.clickRight(any(Locatable.class)))
                .thenReturn(true);
        when(mockedRSInteractor.clickRight(any(ViewportEntity.class)))
                .thenReturn(true);
        
        when(mockedRSInteractor.getClient())
                .thenReturn(mockedClient);
        when(mockedRSInteractor.getLocalPlayer())
                .thenReturn(mockedPlayer);
        when(mockedRSInteractor.getMap())
                .thenReturn(mockedWorldMap);
        when(mockedRSInteractor.getTile(any(Point.class)))
                .then(CALLS_REAL_METHODS);
        when(mockedRSInteractor.getWidget(anyInt()))
                .thenReturn(null);
        when(mockedRSInteractor.getWidgetChild(anyInt(), anyInt()))
                .thenReturn(null);
    }
    
    /**
     * Returns the RSInteractor Mock
     * @return the RSInteractor Mock
     */
    public RSInteractor getRSInteractor() {
        return mockedRSInteractor;
    }
    
    /**
     * Returns the Client Mock
     * @return the Client Mock
     */
    public Client getClient() {
        return mockedClient;
    }
    
    /**
     * Returns the Player Mock
     * @return the Player Mock
     */
    public Player getPlayer() {
        return mockedPlayer;
    }
    
    /**
     * Returns the WorldMap Mock
     * @return the WorldMap Mock
     */
    public WorldMap getWorldMap() {
        return mockedWorldMap;
    }
    
    /**
     * Tests if the RSInteractable Mock returns the correct mocks.
     */
    @Test public void testInitialSetup() {
        assertEquals(getPlayer(),   getRSInteractor().getLocalPlayer());
        assertEquals(getWorldMap(), getRSInteractor().getMap());
        assertEquals(getClient(),   getRSInteractor().getClient());
    }
}
