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
package net.pgrid.loader.util;

import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

import static net.pgrid.loader.util.Logger.Verbosity.DEBUG;
import static net.pgrid.loader.util.Logger.Verbosity.NORMAL;
import static net.pgrid.loader.util.Logger.Verbosity.QUIET;

/**
 * Custom Logging facility allowing for faster logging and more
 * application-specific control options.
 * <p/>
 * @author Patrick Kramer
 */
public class Logger {

    private static PrintStream defaultTarget = System.out;
    
    /**
     * Sets the default target PrintStream used to create new Loggers.
     * This setting will not affect existing Loggers.
     * @param target the new target PrintStream
     */
    public static void setDefaultTarget(PrintStream target) {
        if (target != null) {
            defaultTarget = target;
        }
    }
    
    /**
     * Maximum length of the name of a Logger.
     */
    public static final int MAX_NAME_LENGTH = 12;
    /**
     * Empty prefix inserted before each line in a multi-line log message.
     */
    public static final String EMPTY_PREFIX;

    static {
        // The EMPTY_PREFIX is automatically constructed once using the 
        // MAX_NAME_LENGTH field.
        StringBuilder b = new StringBuilder(MAX_NAME_LENGTH + 3);
        do {
            b.append(' ');
        } while (b.length() < MAX_NAME_LENGTH);
        EMPTY_PREFIX = b.append(" | ").toString();
    }
    private static final Map<String, Logger> LOGGERS = new HashMap<>(8);

    /**
     * Returns a Logger with the given name.
     * <p/>
     * If no Logger yet exists with that name, a new Logger is created. If
     * {@code name == null}, {@code name.isEmpty()} or
     * {@code name.length() > MAX_NAME_LENGTH}, the name is invalid and this
     * method returns null.
     * <p/>
     * @param name the name of the requested Logger
     * @return a Logger with the specified name, or null if the name is invalid.
     */
    public static Logger get(String name) {
        Logger l = LOGGERS.get(name);
        if (l == null) {
            try {
                l = new Logger(name);
            } catch (IllegalArgumentException e) {
                // The name is invalid
                return null;
            }
            LOGGERS.put(name, l);
        }
        return l;
    }

    /**
     * Sets the logger with the given name to use the provided PrintStream for
     * output.
     * <p/>
     * If the name is invalid or the target PrintStream is null, this method
     * does nothing and returns null. Else, the Logger is created if it did not
     * yet exist, and its target is set to the specified PrintStream.
     * <p/>
     * @param name the name of the Logger
     * @param target the new PrintStream the Logger should print to.
     * @return the configured Logger, or null if the Logger name was invalid.
     */
    public static Logger configure(String name, PrintStream target) {
        Logger l = LOGGERS.get(name);
        if (l == null) {
            try {
                l = new Logger(name, target);
                LOGGERS.put(name, l);
            } catch (IllegalArgumentException e) {
                return null;
            }
        } else {
            l.setTarget(target);
        }
        return l;
    }

    /**
     * returns a Set containing all created Logger instances.
     * <p/>
     * Note that a new Set is created for each invocation. The Set can be
     * modified without affecting the Collection of Loggers maintained within
     * this Class.
     *
     * @return a Set containing all created Logger instances.
     */
    public static Set<Logger> getAll() {
        return new HashSet<>(LOGGERS.values());
    }

    /**
     * Enum representing various Logging levels.
     * <p/>
     * These are used to decide whether to print additional info alongside log messages,
     * and how much info is added.
     */
    public static enum Verbosity {
        /** Displays log traces and full stack traces for exceptions. */
        DEBUG,
        /** Displays log traces and short stack traces for exceptions. */
        VERBOSE,
        /** Displays no log traces and short stack traces for exceptions. */
        NORMAL,
        /** Displays no trace information whatsoever. */
        QUIET
    }
    private static volatile Verbosity level = NORMAL;

    /** 
     * Sets the verbosity of the Loggers.
     * <p/>
     * This setting affects all Loggers.
     * <p/>
     * @param newMode the new Verbosity level
     */
    public static void setVerbosity(Verbosity newMode) {
        level = newMode;
    }

    /**
     * @return the current verbosity level
     */
    public static Verbosity getVerbosity() {
        return level;
    }
    
    // -------------------------------------------------------------------------
    private String name;
    private String prefix;
    private PrintStream target;

    /**
     * Creates a Logger with the given name.
     * <p/>
     * The Logger prints to {@code System.out}.
     * @param name the Logger name
     * @throws     IllegalArgumentException when the name is invalid.
     */
    protected Logger(String name) {
        if (name == null || name.isEmpty() || name.length() > MAX_NAME_LENGTH) {
            throw new IllegalArgumentException();
        }
        this.name = name;
        this.target = defaultTarget;
    }

    /**
     * Creates a Logger with the given name.
     * <p/>
     * The Logger prints to the given PrintStream.
     * <p/>
     * @param name   the Logger name
     * @param target the target PrintStream.
     * @throws       IllegalArgumentException when the name is invalid, or the 
     *               PrintStream is null.
     */
    protected Logger(String name, PrintStream target) {
        if (name == null || name.isEmpty() || name.length() > MAX_NAME_LENGTH
                || target == null) {
            throw new IllegalArgumentException();
        }
        this.name = name;
        this.target = target;
    }

    /**
     * @return the name of this Logger
     */
    public String getName() {
        return name;
    }

    /**
     * @return the target of this Logger
     */
    public synchronized PrintStream getTarget() {
        return target;
    }

    /**
     * Sets the target PrintStream of this Logger.
     * <p/>
     * If {@code target == null}, this method does nothing.
     * @param target the new target PrintStream
     */
    protected synchronized void setTarget(PrintStream target) {
        if (target != null) {
            this.target = target;
        }
    }

    /**
     * Returns the line prefix for log messages.
     * <p/>
     * Subclasses can use this method to prefix each line when overriding the 
     * {@code log(String)} and / or {@code describe(Throwable)} methods.
     * @return the prefix used to prepend each line with.
     */
    protected String getPrefix() {
        if (prefix == null) {
            StringBuilder b = new StringBuilder(MAX_NAME_LENGTH + 3);
            b.append(name);
            while (b.length() < MAX_NAME_LENGTH) {
                b.append(' ');
            }
            b.append(" | ");
            prefix = b.toString();
        }
        return prefix;
    }

    /**
     * Logs the given message to this Logger's target PrintStream.
     * @param message the message to log.
     */
    public synchronized void log(String message) {
        target.print(getPrefix());
        String[] lines = message.split("\n");
        int nLines = lines.length;
        if (nLines != 0) {
            target.println(lines[0]);
            for (int i = 1; i < nLines; i++) {
                target.print(EMPTY_PREFIX);
                target.println(lines[i]);
            }
        } else {
            // We print a newLine after the empty prefix in case of an empty message.
            target.println();
        }
        if (getVerbosity() == DEBUG) {
            Thread t = Thread.currentThread();
            StackTraceElement[] trace = t.getStackTrace();
            if (trace.length > 2) {
                StackTraceElement e = trace[2]; // element describing Logger call
                target.append(EMPTY_PREFIX).append("  from ").append(e.getClassName())
                        .append(".").append(e.getMethodName()).append(" (line ")
                        .append(String.valueOf(e.getLineNumber())).append(")");
                target.println();
            }
        }
    }
    
    /**
     * Logs a message to this Logger's target PrintStream.
     * 
     * The message may consist of multiple values of any type. This method
     * appends their String values to the target PrintStream, making this
     * method slightly faster when invoking Logger.log(String) would require String 
     * concatenations.
     * 
     * No stack trace information is printed when this method is invoked, 
     * regardless of the set Verbosity.
     * @param message the message to print
     */
    public synchronized void log(Object... message) {
        target.print(getPrefix());
        for (Object o : message) {
            target.append(String.valueOf(o));
        }
        target.println();
    }

    /**
     * Prints info about the given Throwable to this Logger.
     * <p/>
     * It prints the type of Throwable, the Throwable's message and its stack trace.
     * @param t the Throwable to describe
     */
    public synchronized void describe(Throwable t) {
        target.print(getPrefix());
        if (t != null) {
            target.append(t.getClass().getSimpleName()).append(" occurred: ")
                    .append(t.getMessage());
            target.println();
            printStackTrace(t.getStackTrace());
        } else {
            target.println("No Exception occurred");
        }
    }
    
    /**
     * Logs the message to the Logger, together with the given Throwable.
     * <p/>
     * This method effectively combines the {@code log(String)} and 
     * {@code describe(Throwable)} methods.
     * @param message the message to print
     * @param t the Throwable
     */
    public synchronized void log(String message, Throwable t) {
        if (message == null || message.isEmpty()) {
            describe(t);
        } else {
            log(message);
            if (t != null) {
                target.append(EMPTY_PREFIX).append("caused by ")
                      .append(t.getClass().getSimpleName()).append(": ")
                      .append(t.getMessage());
                target.println();
                printStackTrace(t.getStackTrace());
            }
        }
    }

    private void printStackTrace(StackTraceElement[] trace) {
        if (getVerbosity() == QUIET) {
            return; 
        }
        int l = trace.length;
        int max = (getVerbosity() == DEBUG ? 8 : 2);
        int leftOver = l - max;
        max = l > max ? max : l;
        for (int i=0;i < max;i++) {
            StackTraceElement e = trace[i];
            target.append(EMPTY_PREFIX).append("  in ").append(e.getClassName())
                    .append(".").append(e.getMethodName()).append(" (line ")
                    .append(String.valueOf(e.getLineNumber())).append(")");
            target.println();
        }
        if (leftOver > 0) {
            target.append(EMPTY_PREFIX).append("(").append(String.valueOf(leftOver))
                    .append(" more...)").println();
        }
    }
}
