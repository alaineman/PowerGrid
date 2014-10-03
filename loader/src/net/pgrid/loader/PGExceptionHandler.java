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
package net.pgrid.loader;

import net.pgrid.loader.util.Logger;

/**
 * Custom UncaughtExceptionHandler.
 *
 * This class checks if the Exception was caused on a PG Thread or some
 * other Thread. In the last case, no stack trace is printed to prevent
 * long obfuscated (and as such useless) Runescape stack traces.
 */
public class PGExceptionHandler implements Thread.UncaughtExceptionHandler {
    private static final Logger LOGGER = Logger.get("UNCAUGHT");

    @Override
    public void uncaughtException(Thread thread, Throwable t) {
        LOGGER.log("Exception on Thread \"" + thread.getName() + "\":", t);
        if (!thread.getName().startsWith("PG_")) {
            // do not print stack traces of (obfuscated) RS classes,
            // but use the System.out PrintStream to send it to the
            // runescape.log file.
            System.out.append("Uncaught Exception in Runescape or on AWT Thread \"")
                    .append(thread.getName()).println("\":");
            System.out.append("  ").append(t.getClass().getSimpleName())
                    .append(": ").println(t.getMessage());
        }
    }
    
}
