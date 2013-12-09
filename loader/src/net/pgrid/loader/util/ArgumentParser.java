package net.pgrid.loader.util;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import net.pgrid.loader.logging.Logger;

/**
 * Parses command line arguments and provides easy checking if certain flags 
 * are set or certain options are given.
 * @author Patrick Kramer
 */
public class ArgumentParser {
    private static final Logger LOGGER = Logger.get("INPUT");
    
    private final Set<String> flags = new HashSet<>(8);
    private final Map<String, String> options = new HashMap<>(8);
    
    /**
     * parses the input arguments and adds them to the detected arguments.
     * @param args the input arguments.
     */
    public void analyse(String[] args) {
        if (args == null) {
            return;
        }
        int i = 0;
        int l = args.length;
        while (i < l) {
            String s = args[i];
            String key = null;
            boolean match = false;
            switch (s.length()) {
                case 0:
                case 1: // invalid
                    break;
                case 2: // (-.), where '.' is any single character
                    if (s.charAt(0) == '-') {
                        key = String.valueOf(s.charAt(1));
                        match = true;
                    }
                    break;
                default: // (--.*), where .* is any String value
                    if (s.charAt(0) == '-' && s.charAt(1) == '-') {
                        key = s.substring(2);
                        match = true;
                    }
            }
            if (match) {
                if (i < l-1 && args[i].charAt(0) != '-') {
                    i++;
                    options.put(key, args[i]);
                } else {
                    flags.add(key);
                }
            } else {
                LOGGER.log("Ignoring unexpected token in command line arguments: \"" + s + "\"");
            }
            i++;
        }
    }
    
    /**
     * Merges the alias into the option parameter.
     * 
     * It can be used as follows:
     * <pre><code>
     *      merge("debug", "d");
     *      if (hasFlag("debug")) {
     *          // This will execute if either "--debug" or "-d" was in the input
     *      }
     * </code></pre>
     * 
     * After this method returns, the alias is no longer contained in the parsed
     * arguments, and has been merged with the option. If option is given a 
     * value (when using {@code --option value} syntax), then this value will always be kept, even if there is an alias 
     * specifying a different value.
     * @param option the real option name
     * @param alias  the option's alias name to merge.
     */
    public void merge(String option, String alias) {
        if (flags.remove(alias)) {
            flags.add(option);
        }
        String value = options.remove(alias);
        if (value != null && !options.containsKey(option)) {
            options.put(option, value);
        }
    }
    
    /**
     * Returns whether the given flag was contained in the input arguments.
     * @param flag the flag to check
     * @return true if the given flag was contained in the input arguments, false
     *         otherwise.
     */
    public boolean hasFlag(String flag) {
        return flags.contains(flag);
    }
    
    /**
     * Returns the value for the given option key, or null if it does not exist.
     * @param option the option key
     * @return the value for the option key if it exists, null otherwise.
     */
    public String getValue(String option) {
        return options.get(option);
    }
    
    public boolean hasFlags() {
        return !flags.isEmpty();
    }
    
    public boolean hasValues() {
        return !options.isEmpty();
    }
    
    public int flagCount() {
        return flags.size();
    }
    
    public int valueCount() {
        return options.size();
    }
    
    public int argumentCount() {
        return flags.size() + options.size();
    }
}
