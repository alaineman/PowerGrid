/*
 * Copyright (C) 2014 Patrick Kramer, Vincent Wassenaar
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

package net.pgrid.loader.bridge.injection;

import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;
import net.pgrid.loader.AppletFrame;
import net.pgrid.loader.logging.Logger;

/**
 * Utility class for simplified sending of keystroke commands
 * @author Patrick Kramer
 */
public class Keyboard {
    public static final int ALT = KeyEvent.VK_ALT;
    public static final int CTRL = KeyEvent.VK_CONTROL;
    public static final int SHIFT = KeyEvent.VK_SHIFT;
    
    public static final int A = KeyEvent.VK_A;
    public static final int B = KeyEvent.VK_B;
    public static final int C = KeyEvent.VK_C;
    public static final int D = KeyEvent.VK_D;
    public static final int E = KeyEvent.VK_E;
    public static final int F = KeyEvent.VK_F;
    public static final int G = KeyEvent.VK_G;
    public static final int H = KeyEvent.VK_H;
    public static final int I = KeyEvent.VK_I;
    public static final int J = KeyEvent.VK_J;
    public static final int K = KeyEvent.VK_K;
    public static final int L = KeyEvent.VK_L;
    public static final int M = KeyEvent.VK_M;
    public static final int N = KeyEvent.VK_N;
    public static final int O = KeyEvent.VK_O;
    public static final int P = KeyEvent.VK_P;
    public static final int Q = KeyEvent.VK_Q;
    public static final int R = KeyEvent.VK_R;
    public static final int S = KeyEvent.VK_S;
    public static final int T = KeyEvent.VK_T;
    public static final int U = KeyEvent.VK_U;
    public static final int V = KeyEvent.VK_V;
    public static final int W = KeyEvent.VK_W;
    public static final int X = KeyEvent.VK_X;
    public static final int Y = KeyEvent.VK_Y;
    public static final int Z = KeyEvent.VK_Z;
    
    public static final int NUM_0 = KeyEvent.VK_0;
    public static final int NUM_1 = KeyEvent.VK_1;
    public static final int NUM_2 = KeyEvent.VK_2;
    public static final int NUM_3 = KeyEvent.VK_3;
    public static final int NUM_4 = KeyEvent.VK_4;
    public static final int NUM_5 = KeyEvent.VK_5;
    public static final int NUM_6 = KeyEvent.VK_6;
    public static final int NUM_7 = KeyEvent.VK_7;
    public static final int NUM_8 = KeyEvent.VK_8;
    public static final int NUM_9 = KeyEvent.VK_9;
    
    private Keyboard() {}
    
    private static Component target = null;
    
    public static void type(String str) {
        type(str, 0);
    }
    
    public static void type(String str, int delay) {
        if (str != null) {
            for (int i=0;i<str.length();i++) {
                type(str.charAt(i), delay);
            }
        }
    }
    
    public static void type(String str, int... delays) {
        if (delays == null || delays.length == 0) {
            type(str, 0);
        } else {
            if (str != null) {
                int delayPos = 0;
                for (int i=0;i<str.length();i++) {
                    System.out.println("Typing: " + str.charAt(i) + " with delay " + delays[delayPos]);
                    type(str.charAt(i), delays[delayPos]);
                    delayPos = (delayPos + 1) % delays.length;
                }
            }
        }
    }
    
    public static void type(char c, int delay) {
        int keyCode = KeyEvent.getExtendedKeyCodeForChar(c);
        boolean upper = Character.isUpperCase(c);
        if (upper) hold(SHIFT);
        wait(delay / 10);
        hold(keyCode);
        wait(delay / 5);
        typeImpl(c, (upper ? SHIFT : 0));
        wait(delay / 5);
        release(keyCode);
        wait(delay / 10);
        if (upper) release(SHIFT);
        wait(2 * delay / 5);
    }
    
    public static void type(char c, int modifiers, int delay) {
        int keyCode = KeyEvent.getExtendedKeyCodeForChar(c);
        boolean hasShift = (modifiers & SHIFT) != 0;
        boolean hasAlt   = (modifiers & ALT  ) != 0;
        boolean hasCtrl  = (modifiers & CTRL ) != 0;
        
        if (hasShift) hold(SHIFT);
        if (hasAlt) hold(ALT);
        wait(delay / 6);
        if (hasCtrl) hold(CTRL);
        wait(delay / 6);
        hold(keyCode);
        typeImpl(c, modifiers);
        wait(delay / 3);
        if (hasAlt) release(ALT);
        if (hasCtrl) release(CTRL);
        wait(delay / 6);
        if (hasShift) release(SHIFT);
        wait(delay / 6);
    }
    
    public static void type(char c) {
        type(c, 0);
    }
    
    private static void typeImpl(char c, int modifiers) {
        KeyEvent event = new KeyEvent(target, KeyEvent.KEY_TYPED, 
            System.currentTimeMillis(), modifiers, 
                KeyEvent.VK_UNDEFINED, c);
        for (KeyListener kl : target.getKeyListeners()) {
            kl.keyTyped(event);
        }
    }
    
    public static void hold(int keyCode) {
        KeyEvent event = new KeyEvent(target, KeyEvent.KEY_PRESSED,
            System.currentTimeMillis(), 0, keyCode, KeyEvent.CHAR_UNDEFINED);
        for (KeyListener kl : target.getKeyListeners()) {
            kl.keyPressed(event);
        }
    }
    
    public static void release(int keyCode) {
        KeyEvent event = new KeyEvent(target, KeyEvent.KEY_RELEASED,
            System.currentTimeMillis(), 0, keyCode, KeyEvent.CHAR_UNDEFINED);
        for (KeyListener kl : target.getKeyListeners()) {
            kl.keyReleased(event);
        }
    }
    
    public static void wait(int delay) {
        if (delay > 0) try {
            Thread.sleep(delay);
        } catch (InterruptedException e) {}
    }
    
    public static void setTargetComponent(Component target) {
        Keyboard.target = target;
    }
    
    public static void main(String args[]) {
        net.pgrid.loader.PGLoader.main(args);
        AppletFrame pgFrame = net.pgrid.loader.PGLoader.INSTANCE.getFrame();
        
        final JTextField testField = new JTextField();
        testField.setPreferredSize(new Dimension(200, 24));
        JFrame frame = new JFrame("TestFrame");
        frame.setLayout(new BorderLayout());
        JButton inject = new JButton("Inject!");
        setTargetComponent(pgFrame.getCanvas());
        inject.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        String txt = testField.getText();
                        Logger.get("INJECTOR").log("Injecting String: " + txt);
                        type(txt,
                                // This list of ints is probably randomized 
                                // in the final implementation
                                43, 23, 54, 33, 75, 90, 65, 75, 54);
                    }
                }, "Injector").start();
            }
        });
        
        frame.add(testField, "Center");
        frame.add(inject, "East");
        frame.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        frame.pack();
        frame.setLocation(pgFrame.getX(), pgFrame.getY() - frame.getHeight());
        frame.setVisible(true);
        
    }
}
