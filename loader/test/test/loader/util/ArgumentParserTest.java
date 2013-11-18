package test.loader.util;

import net.pgrid.loader.util.ArgumentParser;
import static org.junit.Assert.*;
import org.junit.Test;

/**
 * JUnit test class for {@code net.pgrid.loader.util.ArgumentParser}.
 * @author Patrick Kramer
 */
public class ArgumentParserTest {
    
    private final ArgumentParser parser = new ArgumentParser();
    
    @Test 
    public void testEmptyArguments() {
        parser.analyse(new String[0]);
        
        assertFalse(parser.hasFlags());
        assertFalse(parser.hasValues());
    }
    
    @Test
    public void testSingleFlagLong() {
        parser.analyse(new String[] { "--testFlag" });
        
        assertTrue(parser.hasFlag("testFlag"));
        assertEquals(1, parser.argumentCount());
    }
}
