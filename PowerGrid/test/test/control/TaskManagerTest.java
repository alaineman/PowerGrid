package test.control;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import static org.mockito.Mockito.*;
import org.mockito.runners.MockitoJUnitRunner;
import powergrid.control.TaskManager;
import powergrid.control.listeners.TaskListener;
import powergrid.tasks.StepTask;
import powergrid.tasks.Task;

@RunWith(MockitoJUnitRunner.class)
public class TaskManagerTest {
    
    public TaskManager tm;
    
    @Mock public static Task mockedTask;
    @Mock public static StepTask mockedStepTask;
    @Mock public static TaskListener mockedListener;
    
    @Before public void setup() {
        tm = new TaskManager();
        
        when(mockedStepTask.getPriority()).thenReturn(0);
        when(mockedTask.getPriority()).thenReturn(3);
        when(mockedTask.compareTo(mockedStepTask)).thenReturn(-3);
        when(mockedStepTask.compareTo(mockedTask)).thenReturn(3);
    }
    
    @Test public void testAssignTask() {
        tm.assignTask(mockedTask);
        assertEquals(1,tm.tasksPending());
        assertEquals(mockedTask, tm.checkNextTask());
    }
    
    @Test public void testAssignTaskTwice() {
        tm.assignTask(mockedTask);
        assertFalse(tm.assignTask(mockedTask));
        assertEquals(1, tm.tasksPending());
    }
    
    @Test public void testAssignMultipleTasks() {
        tm.assignTask(mockedTask);
        tm.assignTask(mockedStepTask);
        assertEquals(2, tm.tasksPending());
    }
    
    @Test public void testAssignTasksDifferentPriorities() {
        tm.assignTask(mockedStepTask);
        tm.assignTask(mockedTask);
        assertEquals(mockedTask, tm.checkNextTask());
    }
    
    @Test public void testAssignCustomPriority() {
        tm.assignTask(mockedTask,4);
        verify(mockedTask).setPriority(4);
    }
    
    @Test public void testRemoveTask() {
        tm.assignTask(mockedTask);
        assertTrue(tm.removeTask(mockedTask));
        assertEquals(0, tm.tasksPending());
    }
    
    @Test public void testRemoveTaskWithTopPriority() {
        tm.assignTask(mockedTask);
        tm.assignTask(mockedStepTask);
        tm.removeTask(mockedTask);
        assertEquals(mockedStepTask, tm.checkNextTask());
    }
    
    @Test public void testRemoveNonExistentTask() {
        tm.assignTask(mockedTask);
        assertFalse(tm.removeTask(mockedStepTask));
        assertEquals(1, tm.tasksPending());
    }
    
    @Test public void testLoopExecutesTask() {
        tm.assignTask(mockedTask);
        tm.loop();
        assertEquals(0, tm.tasksPending());
        verify(mockedTask).execute();
    }
    
    @Test public void testLoopWithNoTasks() {
        tm.loop();
        assertEquals(0, tm.tasksPending());
    }
    
    @Test public void testLoopReturnsCorrectValue() {
        assertEquals(10, tm.loop());
        tm.assignTask(mockedTask);
        assertEquals(20, tm.loop());
    }
    
    @Test public void testRetrieveTask() {
        tm.assignTask(mockedTask);
        assertEquals(mockedTask, tm.retrieveTask());
        assertEquals(0, tm.tasksPending());
    }
    
    @Test public void testRetrieveTaskWithNoTasks() {
        assertNull(tm.retrieveTask());
    }
    
    @Test public void testGetPendingTasks() {
        tm.assignTask(mockedTask);
        tm.assignTask(mockedStepTask);
        assertArrayEquals(new Object[] {mockedTask,mockedStepTask}, tm.getPendingTasks().toArray());
    }
    
    @Test public void testGetPendingTasksWithoutTasks() {
        assertArrayEquals(new Object[0], tm.getPendingTasks().toArray());
    }
    
    @Test public void testClearWithTasks() {
        tm.assignTask(mockedTask);
        tm.assignTask(mockedStepTask);
        tm.clear();
        assertEquals(0, tm.tasksPending());
    }
    
    @Test public void testClearWithoutTasks() {
        tm.clear();
        assertEquals(0, tm.tasksPending());
    }
}
