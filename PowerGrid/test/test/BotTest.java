package test;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.ArgumentCaptor;
import org.mockito.Mock;
import static org.mockito.Mockito.*;
import org.mockito.runners.MockitoJUnitRunner;
import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.api.wrappers.interactive.Player;
import powergrid.Bot;
import powergrid.control.TaskManager;
import powergrid.model.DestinationMap.Destination;
import powergrid.model.Point;
import powergrid.tasks.RestTask;
import powergrid.tasks.Task;
import powergrid.tasks.TravelNearestTask;
import powergrid.tasks.TravelTask;

@RunWith(MockitoJUnitRunner.class)
public class BotTest {
    @Mock public TaskManager mockedTaskManager;
    @Mock public Player mockedPlayer;
    
    public Bot bot;
    
    @Before public void setup() {
        bot = new Bot(mockedTaskManager).withPlayer(mockedPlayer);
        
        when(mockedPlayer.getLocation()).thenReturn(new Tile(2,2,0));
        when(mockedPlayer.isMoving()).thenReturn(false);
        when(mockedPlayer.getAnimation()).thenReturn(-1);
        
        when(mockedTaskManager.tasksPending()).thenReturn(1);
    }
    
    @Test public void testTravelToPoint() {
        Point p = new Point(6,8);
        bot.travelTo(p, 0);
        verify(mockedTaskManager).assignTask(new TravelTask(p,Task.MEDIUM));
    }
    
    @Test public void testTravelToDestination() {
        Destination d = new Destination("TestDestination", new Point(6,2));
        bot.travelTo(d, 500);
        verify(mockedTaskManager).assignTask(new TravelTask(d,500));
    }
    
    @Test public void testTravelToPointWithPriority() {
        Point p = new Point();
        ArgumentCaptor<Task> argument = ArgumentCaptor.forClass(Task.class);
        bot.travelTo(p, 12);
        verify(mockedTaskManager).assignTask(argument.capture());
        assertEquals(12, argument.getValue().getPriority());
    }
    
    @Test public void testAssignRestTask() {
        bot.rest(300, true);
        verify(mockedTaskManager).assignTask(new RestTask(300,true));
    }
    
    @Test public void testGetStateUnknown() {
        assertEquals(Bot.STATE_UNKNOWN, bot.getState());
    }
    
    @Test public void testGetStateIdle() {
        when(mockedTaskManager.tasksPending()).thenReturn(0);
        assertEquals(Bot.STATE_IDLE, bot.getState());
    }
    
    @Test public void testGetStateResting() {
        when(mockedPlayer.getAnimation()).thenReturn(2716);
        assertEquals(Bot.STATE_RESTING, bot.getState());
    }
    
    @Test public void testGetStateWalking() {
        when(mockedPlayer.isMoving()).thenReturn(true);
        assertEquals(Bot.STATE_WALKING, bot.getState());
    }
    
    @Test public void testGetPosition() {
        assertEquals(new Point(2,2,0), bot.getPosition());
    }
    
    @Test public void testGotoNearest() {
        bot.gotoNearest("Varrock", 0);
        verify(mockedTaskManager).assignTask(new TravelNearestTask("Varrock"),0);
    }
    
    @Test public void testGetStateWithoutPlayer() {
        bot = new Bot(mockedTaskManager);
        assertEquals(Bot.STATE_UNKNOWN, bot.getState());
    }
    
    @Test public void getPositionWithoutPlayer() {
        bot = new Bot(mockedTaskManager);
        assertEquals(new Point(),bot.getPosition());
    }
}
