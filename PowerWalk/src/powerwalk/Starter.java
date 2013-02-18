package powerwalk;

import org.powerbot.core.script.ActiveScript;
import org.powerbot.game.api.Manifest;
import powerwalk.tasks.StepTask;
import powerwalk.tasks.Task;

/**
 * Task Manager class for the entire plug-in.
 * <p/>
<<<<<<< HEAD
 * This method deals with starting the plug-in, and continously poll and execute
 * Tasks from the Bot's Task Queue. This is also the ActiveScript class that
 * runs in RSBot.
 * <p/>
 * It also contains publicly accessible logging methods that use
 * java.util.Logger, which can be used to log messages to the console. These
 * methods provide a way to log messages in a similar format regardless of the
 * plug-in.
=======
 * This method deals with continously polling and executing Tasks from the Bot's 
 * Task Queue. This is also the ActiveScript class that runs in RSBot.
>>>>>>> 53f5b15073f0663fdbeac9f50626bf4f23368edf
 * <p/>
 * @author Chronio
 * @author Alaineman
 */
@Manifest(
        authors        = { "Alaineman" , "Chronio" },
        name           = "PowerGrid TaskManager",
        description    = "TaskManager for PowerGrid. It runs the Tasks provided to the Bot",
        version        = PowerGrid.VERSION,
        singleinstance = true)
public class Starter extends ActiveScript {
    
    private static Task currentTask = null;
    
    @Override public void onStart() {
        
    }

    /**
     * executes a Task from the TaskQueue.
     *
     * @return an integer specifying the amount of milliseconds the caller
     * should wait before calling this method again.
     */
    @Override
    public int loop() {
        if (Bot.getBot().tasksPending() > 0) {
            currentTask = Bot.getBot().retrieveTask();
            if (currentTask instanceof StepTask) {
                StepTask task = (StepTask) currentTask;
                PowerGrid.logMessage("Beginning StepTask \"" + task.getName() + "\"...");
                task.start();
                while (task.hasMoreSteps()) {
                    task.execute();
                }
                task.finish();
                PowerGrid.logMessage("StepTask \"" + task.getName() + "\" has ended");
            } else {
                PowerGrid.logMessage("Beginning Task \"" + currentTask.getName() + "\"...");
                currentTask.execute();
                PowerGrid.logMessage("Task \"" + currentTask.getName() + "\" has ended.");
            }
            currentTask = null;
            return 20;
        } else {
            return 10;
        }
    }

    /**
     * Ensures the Mapper is stopped and the ContentFrame is destroyed. Also
     * cleans up as much objects related to PowerWalk as possible.
     */
    @Override public void onStop() {
        
    }

    /**
     * returns the currently running task.
     *
     * @return the currently running task, or null is no task is running
     */
    public static Task currentTask() {
        return currentTask;
    }
}
