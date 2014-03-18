/*
 * Copyright (C) 2014 Patrick Kramer
 *
 * This program is free software: you can redistribute it and/or modify
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

package net.pgrid.loader.draw;

import java.awt.Graphics;

/**
 * Interface for implementing drawing actions.
 * 
 * implementations of this interface can be used to draw on the overlay provided
 * by the PGGlassPane.
 * @author Patrick Kramer
 */
public interface DrawAction {
    /**
     * Performs the drawing task of this DrawAction with the provided Graphics 
     * object.
     * @param g the Graphics object used for drawing. 
     */
    public void draw(Graphics g);
}
