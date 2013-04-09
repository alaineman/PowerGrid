package test.control.interaction.interactor;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import static org.mockito.Matchers.any;
import static org.mockito.Matchers.anyInt;
import org.mockito.Mock;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;
import org.mockito.runners.MockitoJUnitRunner;
import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.api.wrappers.widget.Widget;
import org.powerbot.game.api.wrappers.widget.WidgetChild;
import powergrid.control.interaction.interactor.MinecartInteractor;
import powergrid.model.Point;
import powergrid.model.network.NetworkElement;
import powergrid.model.network.TreeNetwork;
import powergrid.model.world.transportation.Minecart;

@RunWith(MockitoJUnitRunner.class)
public class MinecartInteractorTest extends AbstractInteractorTest {
    
    private MinecartInteractor mi;
    
    @Mock private WidgetChild mockedWidgetChild;
    @Mock private Widget mockedWidget;
    @Mock private Point mockedPoint;
    @Mock private Tile mockedTile;
    @Mock private Minecart mockedMinecart;
    @Mock private Minecart mockedDestination;
    @Mock private TreeNetwork mockedNetwork;
    
    @Override 
    @Before public void setup() {
        super.setup();
        mi = new MinecartInteractor(getWorldMap(),getRSInteractor());
        
        when(mockedMinecart.getNetwork()).thenReturn(mockedNetwork);
        when(mockedDestination.getNetwork()).thenReturn(mockedNetwork);
        when(mockedNetwork.findPath(mockedMinecart, mockedDestination))
                .thenReturn(Arrays.asList(
                new NetworkElement[]{mockedDestination}));
        HashSet<NetworkElement> set = new HashSet<>(3);
        set.add(mockedMinecart);
        set.add(mockedDestination);
        // We provide an explicit cast here to eliminate the return type's 
        // fresh-type variable(? extends NetworkElement).
        when((Set<NetworkElement>) mockedNetwork.getElements()).thenReturn(set);
        when(mockedMinecart.getPosition()).thenReturn(mockedPoint);
        when(mockedPoint.toTile()).thenReturn(mockedTile);
        when(mockedTile.isOnScreen()).thenReturn(true);
        when(getRSInteractor().waitForVisible(any(), anyInt()))
                .thenReturn(true);
        when(getRSInteractor().getWidget(889)).thenReturn(mockedWidget);
        when(mockedWidget.validate()).thenReturn(true);
        when(mockedWidget.getChild(anyInt())).thenReturn(mockedWidgetChild);
        when(getPlayer().getAnimation()).thenReturn(2148,-1);
    }
    
    @Test public void testVerifyMinecart() {
        assertEquals(mockedMinecart,mi.verify(mockedMinecart));
    }
    
    @Test(expected=IllegalArgumentException.class)
    public void testVerifyObject() {
        mi.verify(new Object());
    }
    
    @Test public void testgetOptions() {
        Set<?> options = mi.getOptions(mockedMinecart);
        assertEquals(1,options.size());
        assertTrue(options.contains(mockedDestination));
    }
    
    @Test public void testInteractWithOption() {
        assertTrue(mi.interact(mockedMinecart, mockedDestination));
        verify(getRSInteractor()).click(mockedMinecart);
        verify(getRSInteractor()).click(mockedWidgetChild);
    }
    
    @Test public void testInteractWithoutOption() {
        assertTrue(mi.interact(mockedMinecart));
        verify(getRSInteractor()).click(mockedMinecart);
        verify(getRSInteractor()).click(mockedWidgetChild);
    }
}
