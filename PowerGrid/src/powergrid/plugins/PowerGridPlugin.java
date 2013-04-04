package powergrid.plugins;

import java.util.Arrays;
import java.util.Collection;
import powergrid.PowerGrid;
import powergrid.control.interaction.InteractionController;
import powergrid.control.interaction.interactor.FairyringInteractor;
import powergrid.control.interaction.interactor.MinecartInteractor;
import powergrid.control.uicontrols.RSInteractor;
import powergrid.model.WorldMap;
import powergrid.task.RestTask;
import powergrid.task.Task;
import powergrid.task.TravelNearestTask;
import powergrid.task.TravelTask;

/**
 * This class acts as the container for the PowerGrid publicly accessible tasks.
 * <p/>
 * It provides the standard PowerGrid tasks in the same way as external plugins, 
 * meaning they can be handled in the same way.
 * <p/>
 * The publicly accessible tasks that this plugin provides are RestTask, 
 * TravelTask, and TravelNearestTask.
 * <p/>
 * This Plugin also defines all the default Interactors and Factories and 
 * hooks them into the PowerGrid framework.
 * <p/>
 * @author Chronio
 */
@PluginInfo(
        name = "PowerGrid default Plugin",
        authors = {"Chronio","Alaineman"},
        description = "The default PowerGrid plugin.",
        version = PowerGrid.VERSION
)
public class PowerGridPlugin implements Plugin {
    
    private RSInteractor interactor = null;
    private WorldMap worldmap = null;
    
    private PowerGrid pg = null;
    
    @Override public void withPowerGrid(PowerGrid pg) {
        this.pg = pg;
        interactor = pg.rsInteractor();
        worldmap = pg.worldmap();
    }
    
    /**
     * Creates and hooks all of PowerGrid's default classes into the framework.
     */
    @Override public void setUp() {
        InteractionController ic = pg.interactionController();
        ic.addInteractor(new MinecartInteractor(worldmap,interactor));
        ic.addInteractor(new FairyringInteractor(worldmap,interactor));
    }
    
    @Override public Collection<Class> getPublicTasks() {
        return Arrays.asList(new Class[] {
            RestTask.class,
            TravelNearestTask.class,
            TravelTask.class
        });
    }
    
    @Override
    public <T extends Task> T instantiate(Class<T> clazz) {
        if (RestTask.class.isAssignableFrom(clazz)) {
            return (T) new RestTask();
        }
        if (TravelNearestTask.class.isAssignableFrom(clazz)) {
            return (T) new TravelNearestTask();
        }
        if (TravelTask.class.isAssignableFrom(clazz)) {
            return (T) new TravelTask();
        }
        throw new UnsupportedOperationException("Unsupported Class type");
    }
    
    @Override public void tearDown() {
        InteractionController ic = pg.interactionController();
        
    }

    
}
