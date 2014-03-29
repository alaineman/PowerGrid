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
 * Native implementation of the DrawAction interface.
 * 
 * This allows native code to draw to the PGGlassPane as well.
 * 
 * @author Patrick Kramer
 */
public class NativeDrawAction implements DrawAction {
    /**
     * {@inheritDoc}
     * 
     * This implementation calls all registered native drawing actions.
     */
    @Override
    public native void draw(Graphics g);
}
