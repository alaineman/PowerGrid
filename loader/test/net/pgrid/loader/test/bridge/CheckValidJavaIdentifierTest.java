package net.pgrid.loader.test.bridge;

import java.util.Arrays;
import java.util.List;
import static net.pgrid.loader.bridge.ObfuscatedFieldData.checkValidJavaIdentifier;
import static org.junit.Assert.*;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameters;

/**
 * Test for the <code>checkValidJavaIdentifier(String)</code> method of the 
 * <code>ObfuscatedFieldData</code> class.
 * <p/>
 * 
 * @author Patrick Kramer
 */
@RunWith(Parameterized.class) 
public class CheckValidJavaIdentifierTest {
    
    @Parameters 
    public static List<Object[]> getParams() {
        return Arrays.asList(new Object[][] {
            {null,               false, "Null"},
            {"",                 false, "Empty String"},
            {"java",             true,  "Single part"},
            {"java.lang",        true,  "Two parts"},
            {"java.",            false, "End with period"},
            {".",                false, "Just a period"},
            {"java..lang",       false, "Two periods in a row"},
            {"JavA.LaNg.oBjeCT", true,  "Different Case"},
            {"java.lang;",       false, "End with unexpected symbol"},
            {"java,lang",        false, "Unexpected symbol half-way"},
            {"9Number",          false, "Start with number"},
            {"Number9",          true,  "End with number"},
            {"$Hello",           true,  "Start with $"},
        });
    }
    
    private String param, message;
    private boolean expected;

    public CheckValidJavaIdentifierTest(String param, boolean expected, String message) {
        this.param = param;
        this.message = message;
        this.expected = expected;
    }
    
    @Test 
    public void test() {
        if (expected) {
            assertTrue(message, checkValidJavaIdentifier(param)); 
        } else {
            assertFalse(message, checkValidJavaIdentifier(param));
        }
    }
}
