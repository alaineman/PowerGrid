package test;

import java.io.InputStream;
import powerwalk.control.ToolBox;
import powerwalk.model.XMLNode;

/**
 * Test for the XMLParser in <code>powerwalk.control.ToolBox</code>
 * @author P.Kramer
 */
public class TestXMLParser {
    
    public static final String resource = "powerwalk/data/teleportItems.xml";
    
    /**
     * Tests the ToolBox.getXMLTree(InputStream) and XMLNode.toString() methods 
     * by first loading the XML file defined at resource, then converting it to 
     * an XML tree, and then reproduce the original XML file.
     * 
     * <p> The ToolBox.getXMLTree(InputStream) and XMLNode.toString() methods 
     * both passed this test.</p>
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        InputStream in = ClassLoader.getSystemResourceAsStream(resource);
        XMLNode xml = ToolBox.getXMLTree(in);
        System.out.println(xml.toString());
    }
}
