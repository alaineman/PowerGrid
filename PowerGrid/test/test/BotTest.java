package test;

import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import static org.mockito.Mockito.*;
import org.mockito.runners.MockitoJUnitRunner;
import org.powerbot.game.api.wrappers.Tile;
import org.powerbot.game.api.wrappers.interactive.Player;
import powergrid.Bot;
import powergrid.control.TaskManager;
import powergrid.model.Point;
import powergrid.tasks.TravelTask;

@RunWith(MockitoJUnitRunner.class)
public class BotTest {
    @Mock public TaskManager mockedTaskManager;
    @Mock public Player mockedPlayer;
    
    public Bot bot;
    
    @Before public void setup() {
        bot = new Bot(mockedPlayer,mockedTaskManager);
        
        when(mockedPlayer.getLocation()).thenReturn(new Tile(2,2,0));
        when(mockedPlayer.isMoving()).thenReturn(true);
        when(mockedPlayer.getAnimation()).thenReturn(-1);
    }
    
    @Test public void testTravelToPoint() {
        Point p = new Point();
        bot.travelTo(p, 0);
        verify(mockedTaskManager,times(1)).assignTask(new TravelTask(p,0));
    }
}
