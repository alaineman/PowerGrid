package powergrid.control.listeners;

import powergrid.control.Mapper;

/**
 * Listener that is called every time the Mapper updates the WorldMap
 * @author Chronio
 */
public interface MapperListener {
    /**
     * Called every time the Mapper updates the WorldMap.
     * @param map the Mapper instance caused the event
     */
    public void mapUpdated(Mapper mapper);
}
