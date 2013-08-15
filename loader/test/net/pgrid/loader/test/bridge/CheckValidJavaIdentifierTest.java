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
