/*
 * Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar
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

import java.util.HashMap;
import java.util.Objects;

/**
 * Logger class containing logging methods for exceptions and messages.
 * <p/>
 * Instances of this Class are managed in the static context of this Class.
 * Subclasses should register their instances using this Class' static 
 * <code>provide(Logger)</code> method, to allow externally created Loggers to 
 * be used and called in the same way.
 * <p/>
 * @author Chronio
 */
public class Logger {
    
    private static HashMap<String, Logger> loggers = new HashMap<>(4);
    
    /**
     * Returns the Logger with the specified name, or creates a new one when a 
     * Logger with that name did not yet exist. 
     * <p/>
     * Valid Logger names are not null, and the length must be larger than 0, 
     * but not larger than 8. This is due to the uniform log message formatting 
     * used in both the loader and the PowerGrid bot.
     * 
     * @param name the name of the client
     * @return the Logger instance with the specified name.
     * 
     * @throws IllegalArgumentException when the name is invalid.
     */
    public static Logger get(String name) {
        Logger l = loggers.get(name);
        if (l == null) {
            l = new Logger(name);
            loggers.put(name, l);
        }
        return l;
    }
    
    /**
     * Provides a Logger instance created elsewhere to the static Logger Manager.
     * <p/>
     * The provided Logger is added to the Collection of Loggers if and only if 
     * the provided Logger is not null, and no Logger is yet provided or created 
     * with that name. In that case this method returns true. Otherwise this 
     * method does nothing and returns false.
     * <p/>
     * @param logger the Logger to provide
     * @return true if and only if the provided Logger is added to the 
     *         Collection of Loggers, false otherwise.
     */
    public static boolean provide(Logger logger) {
        if (logger != null) {
            String name = logger.getName();
            if (!loggers.containsKey(name)) {
                loggers.put(name, logger);
                return true;
            }
        }
        return false;
    }
    
    private String name;
    private String prefix;
    private Logger parent = null;
    
    
    
    /**
     * Creates a new Logger with the specified name.
     * <p/>
     * Valid Logger names are not null, and the length must be larger than 0, 
     * but not larger than 8. This is due to the uniform log message formatting 
     * used in both the loader and the PowerGrid bot.
     * <p/>
     * @param name the name of this Logger, max length is 8 due to uniform 
     *             formatting.
     * 
     * @throws IllegalArgumentException when the name is invalid
     */
    protected Logger(String name) {
        if (name == null || name.length() > 8 || name.isEmpty()) {
            throw new IllegalArgumentException("Invalid Logger name");
        }
        this.name = name;
        StringBuilder prefixBuilder = new StringBuilder(10);
        prefixBuilder.append(name);
        while (prefixBuilder.length() < 10) {
            prefixBuilder.append(" ");
        }
        prefix = prefixBuilder.append("| ").toString();
    }

    /**
     * @return the name of this Logger
     */
    public String getName() {
        return name;
    }
    
    /**
     * @return a non-null String with the prefix of this Logger, which is 
     * prepended before log messages to indicate the context of the message.
     * This prefix should have a length of precisely 10 to blend in with 
     * the prefixes given by the default Logger implementation.
     */
    protected String getPrefix() {
        return prefix;
    }

    /**
     * Returns the parent of this Logger.
     * <p/>
     * 
     * @return the parent of this Logger, or null if this parent has no Logger.
     */
    public Logger getParent() {
        return parent;
    }

    /**
     * Sets the parent of this Logger.
     * <p/>
     * Before the parent Logger is set, a check is performed to prevent Loggers 
     * from creating a loop of parents. Setting the parent to null is always 
     * allowed.
     * 
     * @param parent the new parent Logger.
     * @return true if and only if the parent has been set, false otherwise. 
     */
    public boolean setParent(Logger parent) {
        if (parent != null) {
            Logger l = this;
            do {
                if (parent.equals(l)) {
                    return false;
                }
                l = l.getParent();
            } while (l != null);
        }
        this.parent = parent;
        return true;
    }
    
    /**
     * Prints a stack trace of the given Throwable.
     * <p/>
     * This method is faster and more efficient than
     * <code>Throwable.printStackTrace()</code>.
     *
     * @param t the Throwable to describe
     */
    public final void describe(Throwable t) {
        StringBuilder b = new StringBuilder(128);
        b.append(t.getClass().getSimpleName())
                .append(": ").append(t.getMessage()).append("\n");

        Throwable cause = t.getCause();
        if (cause != null) {
            b.append("  caused by: ").append(cause.getClass().getSimpleName())
                    .append(": ").append(cause.getMessage()).append("\n");
        }

        for (StackTraceElement e : t.getStackTrace()) {
            b.append("\tat ").append(e.getClassName()).append(".")
                    .append(e.getMethodName()).append(" (").append(String.valueOf(e.getLineNumber())).append(")\n");
        }

        System.err.println(b);
    }
    
    /**
     * Logs the given message.
     * <p/>
     * When the message could not be logged, this 
     * @param message
     * @return 
     */
    protected boolean logMessage(String message) {
        System.out.println(getPrefix() + message);
        return true;
    }

    /**
     * Logs a message using this Logger
     * <p/>
     * If the provided message is null or the empty String, no action is taken.
     * <p/>
     * If this Logger does not log the message, the message is delegated to this 
     * Logger's parent. If this Logger does not log the message and there is no 
     * parent, the String "-- Message cannot be logged --" is printed to 
     * System.err.
     * <p/>
     * Because of this behavior, it is important for subclasses of this Logger 
     * class to have their parent set to a Logger that always logs the message 
     * (like the default Logger implementation), in the case the subclass can
     * reject the log message. 
     * @param message the message to log
     */
    public final void log(String message) {
        if (message != null && !message.isEmpty()) {
            if (!logMessage(message)) {
                Logger p = getParent();
                if (p != null) {
                    p.log(message);
                } else {
                    System.err.println("CRITICAL | -- Message cannot be logged --");
                }
            }
        }
    }

    @Override
    public boolean equals(Object obj) {
        if (obj != null && obj.getClass().equals(getClass())) {
            return Objects.equals(((Logger)obj).getName(), this.getName());
        }
        return false;
    }

    @Override
    public int hashCode() {
        return 67 + Objects.hashCode(name);
    }

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder("Logger(").append(name).append(")");
        Logger par = getParent();
        if (par != null) {
            res.append(" > ").append(par.toString());
        }
        return res.toString();
    }
}
