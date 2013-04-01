package powergrid.control.listener;

import powergrid.control.Mapper;

/**
 * Listener that is called every time the Mapper updates the WorldMap
 * @author Chronio
 */
public interface MapperListener {
    /**
     * Called every time the Mapper updates the WorldMap.
     * @param mapper the Mapper instance caused the event
     */
    public void mapUpdated(Mapper mapper);
}
