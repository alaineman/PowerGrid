package net.pgrid.loader;

/**
 * Logger class containing logging methods for exceptions and messages.
 *
 * @author Chronio
 */
public class Logger {

    /**
     * Private constructor to prevent instantiation of this utility class.
     */
    private Logger() {
    }

    /**
     * Prints a stack trace of the given Throwable.
     * <p/>
     * This method is faster and more efficient than
     * <code>Throwable.printStackTrace()</code>.
     *
     * @param t the Throwable to describe
     */
    public static void describe(Throwable t) {
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
     * Logs a message to the standard output.
     *
     * @param message the message to log
     */
    public static void log(String message) {
        System.out.println("LOADER   | " + message);
    }
}
