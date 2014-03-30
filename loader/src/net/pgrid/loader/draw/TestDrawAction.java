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

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import javax.swing.UIManager;
import net.pgrid.loader.PGLoader;

/**
 * Testing class for DrawActions.
 * 
 * This class simply draws some text and shapes to the screen.
 * 
 * @author Patrick Kramer
 */
public class TestDrawAction implements DrawAction {
    @Override
    public void draw(Graphics g) {
        PGLoader.out.println("TestDrawAction: draw called");
        
        g.setColor(Color.RED);
        g.setFont(UIManager.getFont("Label.font").deriveFont(Font.BOLD));
        g.drawString("TestDrawAction text", 10, 10);
        
        g.setColor(Color.BLACK);
        g.drawRect(10, 30, 200, 100);
    }

    @Override
    public String toString() {
        return getClass().getSimpleName();
    }
}
