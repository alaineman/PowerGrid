package powerwalk;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.channels.FileChannel;
import org.powerbot.game.api.methods.Environment;

/**
 * Handles basic I/O functions, such as writing and reading from files and moving 
 * or copying files.
 * <p/>
 * @author Chronio
 */
public class IOHandler {
    private IOHandler() {}
    
    /**
     * Copies a File using Java NIO.
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
     * Copies a File using the OS Shell.
     * <p/>
     * This is generally slower than using <code>copy(File,File)</code>, and when 
     * the copy fails, there will be no feedback.
     * @param origin the File to copy from
     * @param destination the File to copy to
     */
    public static void copyShell(File origin, File destination) {
        try {
            String cmd;
            if (System.getProperty("os.name").toLowerCase().contains("windows")) {
                cmd = "copy ";
            } else {
                cmd = "cp ";
            }
            cmd += origin.getAbsolutePath() + " " + destination.getAbsolutePath();
            
            Runtime.getRuntime().exec(cmd);
        } catch (IOException e) {}
    }
    
    /**
     * Writes the given Object's String value to the given File. 
     * @param destination the destination to write to
     * @param data the Object to write
     * @throws IOException when the data could not be written
     */
    public static void write(File destination, Object data) throws IOException {
        if (!destination.canWrite())
            throw new IOException("No access to file: " + destination.getPath());
        try (FileWriter writer = new FileWriter(destination)) {
            writer.write(String.valueOf(data));
        }
    }
    
    /**
     * Writes the given Object's String value to the given File. 
     * <p/>
     * If the provided File is inaccessible, the Object's String value is first 
     * written to a temporary File, and then copied using the copyShell method.
     * <p/>
     * Any and all IOExceptions are caught within this method.
     * <p/>
     * @param destination the destination file to write to.
     * @param data the object to write
     */
    public static void writeSafe(File destination, Object data) {
        if (destination.canWrite())
            try { write(destination, data); }
            catch( IOException e ) {}
        else {
            File dir = Environment.getStorageDirectory();
            if (dir != null) {
                File tempFile = new File(dir, "temp");
                try { 
                    write(tempFile, data); 
                    copyShell(tempFile, destination);
                    tempFile.delete();
                } catch (IOException e) {}
            }
        }
    }
    
    public static String read(File origin) throws IOException {
        StringBuilder sb = new StringBuilder();
        try (FileReader reader = new FileReader(origin)) {
            while (reader.ready()) {
                sb.append(reader.read());
            }
        }
        return sb.toString();
    }
    
    public static String readSafe(File origin) {
        if (origin.canRead()) {
            try { return read(origin); }
            catch (IOException e){}
        }
        File tempFile = new File(Environment.getStorageDirectory(),"tempFile");
        copyShell(origin, tempFile);
        try { 
            String s = read(tempFile);
            tempFile.delete();
            return s;
        }
        catch (IOException e) {}
        return null;
    }
}
