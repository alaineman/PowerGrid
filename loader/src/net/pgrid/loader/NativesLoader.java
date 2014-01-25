/*
 * Copyright (C) 2014 Patrick Kramer
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */

package net.pgrid.loader;

import java.io.File;
import java.io.IOException;
import java.util.Locale;

/**
 * Utility class for loading and starting the native PowerGrid client.
 * 
 * If the native client does not exist, the {@code isPowergridAvailable()} 
 * method returns false. Otherwise, this method returns true.
 * 
 * @author Patrick Kramer
 */
public class NativesLoader {
    private static boolean powergridAvailable;
    
    /**
     * Indicates whether the native PowerGrid code is available as a library.
     * This is false only when the client loader is running without the 
     * PowerGrid native code. If PowerGrid is launched from native code, this
     * value is also true.
     * @return true if the native client is available, false otherwise.
     */
    public static boolean isPowergridAvailable() {
        return powergridAvailable;
    }

    /**
     * Overrides if PowerGrid is available, effectively skipping the check if
     * this is set to true.
     * Note, however, that setting this value to true implies the native loader 
     * is present, though not necessarily as a dynamic library.
     * 
     * Usually, this is called by the PGLoader class when it detects it's 
     * launched by the native client. That prevents this class from checking 
     * again without affecting other classes that depend on the value of
     * {@code isPowergridAvailable()}.
     * @param powergridAvailable whether the native client is present or not.
     */
    public static void setPowergridAvailable(boolean powergridAvailable) {
        NativesLoader.powergridAvailable = powergridAvailable;
    }
    
    /**
     * Checks if the PowerGrid library is available and loads it if it exists.
     * 
     * This method returns true if the native PowerGrid client is available.
     * This may be because it was loaded by this method invocation, because
     * it was loaded in a previous invocation of this method, or the PowerGrid
     * client was marked as available by another class.
     * 
     * If {@code isPowergridAvailable()} returns true when this method is 
     * invoked, this method does nothing and returns true. Else, it attempts to 
     * load the native PowerGrid client as a dynamic native library and returns
     * whether this succeeded.
     * 
     * @return true if PowerGrid is available now, false otherwise.
     */
    public static boolean checkLoadPowerGrid() {
        // If the client has already been marked as available, we don't need to
        // try linking to it here.
        if (powergridAvailable) {
            return true;
        }
        // We can load the native bot client as a JNI library.
        // This requires the library to be named properly depending on the OS.
        File library;
        String osName = System.getProperty("os.name").toLowerCase(Locale.ENGLISH);
        boolean success = false;
        if (osName.contains("win")) {
            library = new File("PowerGrid.dll");
        } else if (osName.contains("mac")) {
            // JNI libraries have .jnilib extension on Mac OS X
            library = new File("libPowerGrid.jnilib");
        } else { // Assume some Unix OS
            library = new File("libPowerGrid.so");
        }
        if (library.exists()) {
            try {
                System.load(library.getCanonicalPath());
                success = true;
            } catch (IOException | UnsatisfiedLinkError ex) {}
        }
        
        powergridAvailable = success;
        return success;
    }
    
    // private constructor prevents instantiation of this utility class
    private NativesLoader() {}
}
