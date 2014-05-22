/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
 * 
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
package net.pgrid.loader;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.URL;
import java.util.jar.JarInputStream;

/**
 * Utility class for the finding a pseudo-unique hash of the Runescape client.
 *
 * This class computes a checksum of the Runescape client. This gives us a 
 * good indication of which game pack we have, so that we can collect
 * the correct information from the updater server.
 *
 * @author Patrick Kramer
 */
public class GamepackIdentifier {

    /**
     * The default URL template to use for creating URLs to 
     */
    public static final String URL_TEMPLATE = 
            "http://pgrid.com/marneus/newupdater/reflection_cache_{hash}.xml";
    
    private final File gamepackFile;

    /**
     * Creates a new 
     * @param gamepackFile 
     */
    public GamepackIdentifier(File gamepackFile) {
        this.gamepackFile = gamepackFile;
    }

    public File getGamepackFile() {
        return gamepackFile;
    }

    public int computeGamepackHash() throws IOException {
        JarInputStream jIn = new JarInputStream(
                             new FileInputStream(gamepackFile));
        return jIn.getManifest().hashCode();
    }
    
    /**
     * Creates an URL instance based on the gamepack hash.
     * 
     * The URL points to the location of {@code URL_TEMPLATE}, with every 
     * occurrence of the String {@code {hash}} replaced with the hash code of
     * the client this instance is linked to.
     * @return a URL based on the hash and the provided template
     * @throws IOException if computing the hash failed, or the resulting 
     *                     URL is invalid.
     */
    public URL createUrl() throws IOException {
        return createUrl(URL_TEMPLATE);
    }
    
    /**
     * Creates an URL instance based on the gamepack hash and the provided 
     * template. 
     * 
     * The URL points to the location of the provided template, with every 
     * occurrence of the String {@code {hash}} replaced with the hash code of
     * the client this instance is linked to.
     * @param template the template String to use
     * @return a URL based on the hash and the provided template
     * @throws IOException if computing the hash failed, or the resulting 
     *                     URL is invalid.
     */
    public URL createUrl(String template) throws IOException {
        int hash = computeGamepackHash();
        return new URL(template.replace("{hash}",String.valueOf(hash)));
    }
}
