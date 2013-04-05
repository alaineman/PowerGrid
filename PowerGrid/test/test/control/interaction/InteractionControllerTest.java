package test.control.interaction;

import java.util.HashSet;
import java.util.Set;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import static org.mockito.Mockito.*;
import org.mockito.runners.MockitoJUnitRunner;
import powergrid.control.interaction.InteractionController;
import powergrid.control.interaction.Interactor;
import powergrid.model.GameTile;
import powergrid.model.OutOfReachException;
import powergrid.model.Point;

@RunWith(MockitoJUnitRunner.class)
public class InteractionControllerTest {
    
    @Mock public Interactor mockedInteractor;
    @Mock public Interactor mockedSpecificInteractor;
    
    public InteractionController ic;
    
    @Before public void setup() throws OutOfReachException {
        ic = new InteractionController();
        
        when(mockedInteractor.interact(anyObject())).thenReturn(true);
        when(mockedInteractor.isMoreFavorableThan(eq(mockedSpecificInteractor), 
                any(Class.class))).thenReturn(false);
        Set<Class<?>> answer = new HashSet(2);
        answer.add(Object.class);
        when(mockedInteractor.getTypes()).thenReturn(answer);
        answer = new HashSet<>(2);
        answer.add(Object.class);
        answer.add(GameTile.class);
        when(mockedSpecificInteractor.getTypes()).thenReturn(answer);
        when(mockedSpecificInteractor.interact(anyObject(), anyObject()))
                .thenReturn(true);
        when(mockedSpecificInteractor.interact(anyObject())).thenReturn(true);
        when(mockedSpecificInteractor.isMoreFavorableThan(eq(mockedInteractor), 
                any(Class.class))).thenReturn(true);
    }
    
    @Test public void testAdd() {
        assertTrue(ic.addInteractor(mockedInteractor));
    }
    
    @Test public void testAddWithOverwriteTrue() {
        ic.addInteractor(mockedInteractor);
        assertTrue(ic.addInteractor(mockedSpecificInteractor));
    }
    
    @Test public void testAddWithoutOverwrite() {
        ic.addInteractor(mockedSpecificInteractor);
        ic.addInteractor(mockedInteractor);
        assertEquals(mockedSpecificInteractor, ic.findInteractor(Object.class));
    }
    
    @Test public void testInteractNoOption() throws OutOfReachException {
        ic.addInteractor(mockedInteractor);
        Object o = new Object();
        assertTrue(ic.interact(o));
        verify(mockedInteractor).interact(o);
    }
    
    @Test public void testInteractWithOption() throws OutOfReachException {
        ic.addInteractor(mockedSpecificInteractor);
        Object o1 = new Object();
        Object o2 = new Object();
        assertFalse(o1.equals(o2));
        assertTrue(ic.interact(o1,o2));
        verify(mockedSpecificInteractor).interact(o1,o2);
    }
    
    @Test public void testInteractConcurrentInteractors() 
            throws OutOfReachException {
        ic.addInteractor(mockedInteractor);
        ic.addInteractor(mockedSpecificInteractor);
        Object o = new Object();
        assertTrue(ic.interact(o));
        verify(mockedSpecificInteractor).interact(o);
    }
    
    @Test public void testNoInteractor() throws OutOfReachException {
        assertNull(ic.findInteractor(Object.class));
        assertFalse(ic.interact(new Object()));
    }
    
    @Test public void testInteractWithSubclass() throws OutOfReachException {
        ic.addInteractor(mockedInteractor);
        Point p = new Point();
        assertTrue(ic.interact(p));
        verify(mockedInteractor).interact(p);
    }
}
