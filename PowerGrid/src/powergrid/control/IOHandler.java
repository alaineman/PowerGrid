package powergrid.control;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.channels.FileChannel;

/**
 * Handles basic I/O functions, such as writing and reading from files and moving 
 * or copying files.
 * <p/>
 * @author Chronio
 */
public class IOHandler {
    private IOHandler() {}
    
    /**
     * Copies a File using Java NIO FileChannels.
     * <p/>
     * This is generally the fastest way to copy files, but it will be blocked by 
     * a SecurityManager if the SecurityManager does not allow reading/writing to the
     * given Files.
     * @param origin the File to copy from
     * @param destination the File to copy to
     * @throws IOException when the copy failed
     */
    public static void copy(File origin, File destination) throws IOException {
        if (!origin.canRead() || !destination.canWrite())
            throw new IOException("No read/write permission for given files");
        
        FileChannel from = new FileInputStream(origin).getChannel();
        FileChannel to = new FileOutputStream(destination).getChannel();
        
        to.transferFrom(from, 0, from.size());
    }
    
    /**
     * Writes the given Object's String value to the given File. 
     * <p/>
     * The write can be blocked by a SecurityManager
     * @param destination the destination to write to
     * @param data the Object to write
     * @throws IOException when the data could not be written
     */
    public static void write(File destination, String data) throws IOException {
        if (!destination.canWrite())
            throw new IOException("No access to file: " + destination.getPath());
        try (FileWriter writer = new FileWriter(destination)) {
            writer.write(data);
        }
    }
    
    /**
     * Reads a File from the specified location and returns the result as a String.
     * <p/>
     * A SecurityException may be thrown if a SecurityManager does not allow access
     * to the given File.
     * @param origin the File to read from
     * @return the result String
     * @throws IOException when the read operation failed.
     */
    public static String read(File origin) throws IOException {
        StringBuilder sb = new StringBuilder();
        try (FileReader reader = new FileReader(origin)) {
            while (reader.ready()) {
                sb.append(reader.read());
            }
        }
        return sb.toString();
    }
}
