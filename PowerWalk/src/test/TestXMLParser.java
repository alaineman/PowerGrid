package test;

import java.io.InputStream;
import powerwalk.control.XMLToolBox;
import powerwalk.model.XMLNode;

/**
 * Test for the XMLParser in <code>powerwalk.control.XMLToolBox</code>
 * @author P.Kramer
 */
public class TestXMLParser {
    
    public static final String resource = "powerwalk/data/specialLocations.xml";
    
    /**
     * Tests the XMLToolBox.getXMLTree(InputStream) and XMLNode.toString() methods 
     * by first loading the XML file defined at resource, then converting it to 
     * an XML tree, and then reproduce the original XML file.
     * 
     * <p> The XMLToolBox.getXMLTree(InputStream) and XMLNode.toString() methods 
     * both passed this test.</p>
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        InputStream in = ClassLoader.getSystemResourceAsStream(resource);
        XMLNode xml = XMLToolBox.getXMLTree(in);
        System.out.println(xml.toString());
    }
}
