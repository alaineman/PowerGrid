package powerwalk.model;

import java.util.HashMap;

/**
 * Three-dimensional data structure. 
 * @author P.Kramer
 */
public class Grid {
    
    private HashMap<Integer,HashMap<Integer,GameObject[]>> data;
    private Point offset = new Point(0,0,0);
    
    /**
     * Creates a new Grid with the given maximum dimensions.
     * <p> More memory is allocated as more elements are added</p>
     */
    public Grid() {
        data = new HashMap<>();
    }
    
    public void setOffset(Point p) {
        offset = p.add(new Point(0,0));
    }
    
    /**
     * ensures that memory is allocated for Point p
     * @param p the Point in the Grid to allocate
     */
    private void allocate(Point p) {
        HashMap<Integer,GameObject[]> column = data.get(p.x);
        if (column == null) {
            column = new HashMap<>();
            data.put(p.x, column);
        }
        GameObject[] cell = column.get(p.y);
        if (cell == null) {
            cell = new GameObject[p.z];
            column.put(p.y,cell);
        } else if (cell.length < p.z) {
            GameObject[] largerCell = new GameObject[p.z];
            System.arraycopy(cell, 0, largerCell, 0, cell.length);
            column.put(p.y,largerCell);
        }
    }
    
    /**
     * Sets a GameObject at the given position and returns the GameObject previously at this position
     * @param p the Point to set the GameObject to
     * @param o the GameObject to set
     * @return the GameObject previously at Point p
     */
    public synchronized GameObject set(Point p,GameObject o) {
        p = p.subtract(offset);
        allocate(p);
        GameObject[] cell = data.get(p.x).get(p.y);
        GameObject original = cell[p.z];
        cell[p.z] = o;
        if (o == null) {
            boolean isEmpty = true;
            for (int i=0;i<cell.length;i++) {
                if (cell[i] != null) {
                    isEmpty = false;
                    break;
                }
            }
            if (isEmpty) {
                data.get(p.x).put(p.y,null);
            }
        }
        return original;
    }
    
    /**
     * removes the element stored at Point p from the Grid and returns this element.
     * returns null if no such element was found
     * @param p the position of the element to remove
     * @return the GameObject at this Point
     */
    public synchronized GameObject delete(Point p) {
        return set(p,null);
    }
    
    public GameObject get(Point p) {
        p = p.subtract(offset);
        GameObject elem = null;
        try {
            elem = data.get(p.x).get(p.y)[p.z];
        } catch (ArrayIndexOutOfBoundsException | NullPointerException e) {}
        return elem;
    }
}
