/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package powerwalk.model.interact;

import java.util.HashMap;
import powerwalk.model.GameObject;

/**
 * Represents a Lodestone in the RSBot environment.
 *
 * @author Alaineman
 * @author P.Kramer
 */
public class Lodestone extends GameObject {

    /**
     *
     */
    private String locationName = "";
    /**
     *
     */
    private static HashMap<String, Lodestone> lodestones;

    /**
     *
     * @param x
     * @param y
     * @param z
     * @param rawNumber
     * @param loc
     */
    private Lodestone(int x, int y, int z, int rawNumber, String loc) {
        super(x, y, z, rawNumber);
        locationName = loc;
    }

    /**
     *
     * @param dest
     * @return
     */
    public static Lodestone getLodestone(String dest) {
        return null;
    }

    /**
     *
     * @param dest
     * @return
     */
    public static Lodestone addLodestone(String dest) {
        return null;
    }
}
