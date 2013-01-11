package powerwalk.model;

import java.lang.reflect.InvocationTargetException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map.Entry;
import powerwalk.Starter;
import powerwalk.model.interact.Lodestone;
import powerwalk.model.interact.handlers.LunarIsleShip;
import powerwalk.model.interact.handlers.PiratesCove;
import powerwalk.model.interact.handlers.WaterbirthIsle;
import powerwalk.model.interact.handlers.manifold.*;
import powerwalk.model.world.Door;
import powerwalk.model.world.Enemy;
import powerwalk.model.world.Person;
import powerwalk.model.world.Wall;

/**
 * Three-dimensional data structure for GameObjects.
 * @author Chronio
 */
public class Grid {
    
    private HashMap<Integer,HashMap<Integer,GameObject[]>> data;
    private Point offset = new Point(0,0,0);
    private int size = 0;
    
    /**
     * Creates a new Grid.
     */
    public Grid() {
        data = new HashMap<>();
    }
    
    /**
     * Sets the offset to the given value.
     * This does not change the location of the elements on the Grid, so the 
     * elements of this Grid may be in the wrong place after calling this method.
     * @param p the new offset
     */
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
            cell = new GameObject[p.z+1];
            column.put(p.y,cell);
        } else if (cell.length < p.z+1) {
            GameObject[] largerCell = new GameObject[p.z+1];
            System.arraycopy(cell, 0, largerCell, 0, cell.length);
            column.put(p.y,largerCell);
        }
    }
    
    /**
     * returns the amount of elements in the Grid
     * @return the amount of elements in the Grid
     */
    public int size() {
        return size;
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
        if (original == null && o != null) size++;
        if (original != null && o == null) size--;
        return original;
    }
    
    /**
     * A list of classes that are recognized by the Grid as potential types for 
     * raw values. This field can be modified, but classes in this array will only be 
     * used if they define the following field:
     * <p><code>public static final int[] values</code></p>
     * <p>The values in this <code>int[]</code> must be sorted ascending.</p>
     */
    public static Class<?>[] objectclasses = new Class<?>[] {
        Wall.class,          Enemy.class,          Person.class,
        Door.class,          Lodestone.class,      Canoe.class,
        Minecart.class,      MagicCarpet.class,    SpiritTree.class,
        HotAirBalloon.class, GnomeGlider.class,    FairyRing.class,
        CharterShip.class,   WaterbirthIsle.class, LunarIsleShip.class,
        PiratesCove.class};
    
    /**
     * Sets a GameObject of the correct type to the specified Point.
     * <p>This method makes use of the <code>objectclasses</code> field to find 
     * the appropriate class for the given value.</p>
     * @param p the Point the GameObject has to be stored on
     * @param value the raw value for the object
     * @return the GameObject previously at Point p.
     */
    public synchronized GameObject set(Point p, int value) {
        // shady "reflect magic" corner
        if (value == 0) {
            return set(p,new GameObject(p.x,p.y,p.z,0));
        }
        if (value < 0) {
            return set(p,new Wall(p.x,p.y,p.z,value));
        }
        
        for (Class<?> c : objectclasses) {
            if (GameObject.class.isAssignableFrom(c)) {
                try { 
                    Object v = c.getDeclaredField("values").get(null);
                    if (v instanceof int[]) {
                        int[] values = (int[]) v;
                        if (Arrays.binarySearch(values, value) >= 0) {
                            Object o = c.getConstructor(new Class<?>[] {int.class,int.class,int.class,int.class})
                                          .newInstance(new Object[] {  p.x,      p.y,      p.z,     value   });
                            if (o instanceof GameObject) {
                                GameObject g = (GameObject)o;
                                return set(p,g);
                            }
                        }
                    }
                } catch (NoSuchFieldException   | SecurityException     | IllegalArgumentException 
                       | IllegalAccessException | NoSuchMethodException | InstantiationException 
                       | InvocationTargetException e) {}
            }
        }
        return set(p,new GameObject(p.x,p.y,p.z,value));
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
    
    /**
     * Returns the element at the given Point in the Grid
     * @param p the Point to look up
     * @return the value stored at Point p
     */
    public GameObject get(Point p) {
        p = p.subtract(offset);
        GameObject elem = null;
        try {
            elem = data.get(p.x).get(p.y)[p.z];
        } catch (ArrayIndexOutOfBoundsException | NullPointerException e) {}
        return elem;
    }
    
    /**
     * Reduces the memory this Grid occupies by rebuilding the internal structure of the Grid.
     * <p>Please note that this operation may take a long time to complete. Furthermore, future 
     * set() operations on this Grid may be slower due to reduced reserved space.</p>
     */
    public synchronized void purge() {
        for (Entry<Integer,HashMap<Integer,GameObject[]>> col : data.entrySet()) {
            if (col.getValue() == null || col.getValue().isEmpty()) {
                data.remove(col.getKey());
                continue;
            }
            for (Entry<Integer,GameObject[]> e : col.getValue().entrySet()) {
                if (e.getValue() == null || e.getValue().length == 0) {
                    col.getValue().remove(e.getKey());
                    continue;
                }
                for (int i=e.getValue().length-1; i>=0; i--) {
                    if (e.getValue()[i] != null) {
                        // i is the last occupied slot
                        GameObject[] reduced = new GameObject[i+1];
                        System.arraycopy(e.getValue(),0,reduced,0,i+1);
                        break;
                    }
                }
            }
        }
    }
    
    /**
     * creates an XML tree representation of the Grid and returns it.
     * @return an XML tree representation of the Grid
     */
    public XMLNode getXMLTree() {
        HashMap<String,String> atts = new HashMap<>(2);
        atts.put("columns", String.valueOf(data.size()));
        ArrayList<XMLNode> columns = new ArrayList<>(data.size());
        for (Entry<Integer,HashMap<Integer,GameObject[]>> column : data.entrySet()) {
            // for each column in the Grid
            HashMap<String,String> columnAtts = new HashMap<>(2);
            columnAtts.put("index",String.valueOf(column.getKey()));
            ArrayList<XMLNode> cells = new ArrayList<>(column.getValue().size());
            for (Entry<Integer,GameObject[]> cell : column.getValue().entrySet()) {
                // for each cell in that column
                HashMap<String,String> cellAtts = new HashMap<>(2);
                cellAtts.put("index", String.valueOf(cell.getKey()));
                ArrayList<XMLNode> objects = new ArrayList<>(cell.getValue().length);
                for (GameObject o : cell.getValue()) {
                    // for each object in that cell
                    if (o != null) {
                        HashMap<String,String> objectAtts = new HashMap<>(2);
                        objectAtts.put("value",String.valueOf(o.getRawNumber()));
                        objectAtts.put("plane", String.valueOf(o.getPosition().z));
                        objectAtts.put("class", o.getClass().getName());
                        objects.add(new XMLNode("object",objectAtts,null));
                    }
                }
                cells.add(new XMLNode("cell",cellAtts,objects));
            }
            columns.add(new XMLNode("column",columnAtts,cells));
        }
        return new XMLNode("grid",atts,columns);
    }
    
    /**
     * parses the data from the provided XML structure if it represents a grid.
     * <p>Only XMLNodes with the tag "grid" will be accepted.</p>
     * @param root the root Node of the grid structure.
     */
    public synchronized void fillFromXML(XMLNode root) {
        if (root == null) return;
        try {
            if (root.getTag().equals("grid")) {
                for (XMLNode column : root.children()) {
                    fillColumn(column);
                }
            }
        } catch (NumberFormatException nfe) {}
    }
    
    private void fillColumn(XMLNode col) {
        if (col.getTag().equals("column")) {
            int index = Integer.parseInt(col.getAttributes().get("index"));
            for (XMLNode cell : col.children()) {
                fillCell(index,cell);
            }
        }
    }
    
    private void fillCell(int colIndex,XMLNode cell) {
        if (cell.getTag().equals("cell")) {
            int cellIndex = Integer.parseInt(cell.getAttributes().get("index"));
            for (XMLNode o : cell.children()) {
                HashMap<String,String> atts = o.getAttributes();
                int z = Integer.parseInt(atts.get("plane"));
                Point p = new Point(colIndex,cellIndex,z); 
                int value = Integer.parseInt(atts.get("value"));
                if (atts.containsKey("class")) {
                    try {
                        // attempt creation of right type Object
                        Object object = Class.forName(atts.get("class"))
                                    .getConstructor(new Class<?>[] {int.class,int.class,int.class,int.class})
                                      .newInstance(new Object[] {  p.x,      p.y,      p.z,      value});
                        
                        GameObject g = (GameObject)object;
                        set(p,g);
                    } catch (ClassNotFoundException    | InstantiationException | IllegalAccessException 
                           | InvocationTargetException | NoSuchMethodException  e) {
                        Starter.logMessage("Construction for \"" + o + "\" failed: " + e);
                        set(p,value);
                    }
                } else {
                    set(p,value);
                }
            }
        }
    }
    
    /**
     * returns a XML-formatted representation of this Grid
     * @return a XML-formatted representation of this Grid
     */
    @Override public String toString() {
        return getXMLTree().toString();
    }
}
