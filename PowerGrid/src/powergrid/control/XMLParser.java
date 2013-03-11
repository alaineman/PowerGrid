package powergrid.control;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;
import powergrid.PowerGrid;
import powergrid.model.XMLElement;
import powergrid.model.XMLNode;
import powergrid.model.XMLText;

/**
 * ToolBox that provides methods to read and parse XML files.
 * @author Chronio
 */
public class XMLParser {
    
    private File source;
    private XMLElement tree;
    
    /**
     * Create a new XMLParser for creating an XMLTree from the given File.
     * @param source the File to read from
     */
    public XMLParser(File source) {
        this.source = source;
    }

    /**
     * Returns the File that this XMLParser reads from.
     * @return the File that this XMLParser reads from
     */
    public File getSource() {
        return source;
    }

    /**
     * Returns the parsed XML tree.
     * @return the parsed XML tree
     */
    public XMLElement getTree() {
        if (tree == null) {
            return parse();
        } else {
            return tree;
        }
    }
    
    /**
     * Parses the given File to an XMLElement
     * @return 
     */
    private XMLElement parse() {
        try {
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();
            Document document = builder.parse(source);
            document.getDocumentElement().normalize();
            
            tree = parseNode(document);
        } catch (ParserConfigurationException | SAXException | IOException e) {
            
        }
        return tree;
    }
    
    private XMLElement parseNode(Node n) {
        HashMap<String,String> atts = null;
        ArrayList<XMLNode> children = null;
        if (n.hasAttributes()) {
            NamedNodeMap map = n.getAttributes();
            atts = new HashMap<>((int)(1.5*map.getLength()));
            for (int i=0; i<map.getLength(); i++) {
                Node node = map.item(i);
                atts.put(node.getNodeName(), node.getNodeValue());
            }
        }
        String text = n.getTextContent();
        if (text != null && !text.isEmpty()) 
            children.add(new XMLText(text));
        if (n.hasChildNodes()) {
            NodeList nodes = n.getChildNodes();
            for (int i=0; i<nodes.getLength(); i++) {
                children.add(parseNode(nodes.item(i)));
            }
        }
        return new XMLElement(n.getNodeName(),atts,children);
    }
    
    /**
     * Returns a HashMap containing the attributes and their values from a valid XML-String
     * @param xml The XML-String to parse
     * @return a HashMap containing the attributes and values parsed from xml
     */
    public static HashMap<String,String> getAttributes(String xml) {
        HashMap<String,String> vals = new HashMap<>();
        int tagEnd = xml.indexOf(" ",xml.indexOf("<"));
        if (tagEnd == -1) {
            xml = xml.substring(xml.indexOf("<"),xml.lastIndexOf(">"));
        } else {
            xml = xml.substring(tagEnd,xml.lastIndexOf(">"));
        }
        
        while (!xml.isEmpty()) {
            try {
                xml = xml.trim();
                int is = xml.indexOf("=",0);
                if (is == -1) break;
                int openVal = xml.indexOf("'",is);
                int closeVal  = xml.indexOf("'",openVal+1);
                if (openVal == -1 || closeVal == -1) {
                    openVal = xml.indexOf("\"",is);
                    closeVal = xml.indexOf("\"",openVal+1);
                }
                String att = xml.substring(0, is);
                String val = xml.substring(openVal+1,closeVal);
                vals.put(att, val);
                xml = xml.substring(closeVal+1);
            } catch (StringIndexOutOfBoundsException e) {
                PowerGrid.logMessage("Not the entire XML String could be parsed");
            }
        }
        return vals;
    }
    
    /**
     * Parses and returns the tag name from the given XML-String
     * @param xml the XML-String to parse the tag name for
     * @return the tag name of the XML-String
     */
    public static String getTagFromXML(String xml) {
        int index = xml.indexOf("<");
        int start = index+1;
        int end = xml.indexOf(" ",start);
        if (end == -1) end = xml.indexOf(">");
        else end = Math.min( end, xml.indexOf(">"));
        String res = xml.substring(start,end);
        if (res.startsWith("/")) res = res.substring(1,res.length());
        return res;
    }
    
    /**
     * Parses an XML Tree from the given InputStream
     * @param in the InputStream to parse an XMLTree from
     * @return the XMLTree given by the InputStream, or null when the InputStream 
     *         could not be read.
     */
    public static XMLElement getXMLTree(InputStream in) {
        if (in == null) 
            return null;
        ArrayList<String> lines = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(in))) {
            while (reader.ready()) {
                lines.add(reader.readLine());
            }
            return getXMLTree(lines,0);
        } catch (IOException iox) {
            PowerGrid.logMessage("Could not read the InputStream");
            return null;
        }
    }
    
    
    
    /**
     * Searches the given XMLElement for direct childElements that have the given attribute set to the given value.
     * @param root the root XMLElement
     * @param attribute the attribute to look for
     * @param value the value this attribute must have in order to be accepted
     * @return an array of XMLNodes matching the filter
     */
    public static XMLElement[] filterNodes(XMLElement root,String attribute,String value) {
        if (attribute == null || root == null || value == null) {
            return null;
        }
        ArrayList<XMLElement> matches = new ArrayList<>();
        for (XMLElement n : root.childElements()) {
            String val = n.get(attribute);
            if (val != null && value.equals(val))
                matches.add(n);
        }
        return matches.toArray(new XMLElement[0]);
    }
    
    /**
     * Creates an XML Tree from the given list of lines, where every String element represents one XML Tag
     * @param lines a List of XML Strings
     * @return an XML tree created from the list of XML Strings
     */
    public static XMLElement getXMLTree(ArrayList<String> lines) {
        return getXMLTree(lines,0);
    }
    
    private static int lineIndex = 0;
    private static XMLElement getXMLTree(ArrayList<String> lines, int start) {
        try {
            lineIndex = start;
        
        String root = lines.get(start);
        if (root.contains("<!--") ) { // ignore comments
            while (!lines.get(lineIndex).contains("-->")) {
                lineIndex++;
                if (lineIndex >= lines.size()) break;
            }
            return null;
        }
        if (root.isEmpty() ||                                 // ignore empty lines
           (root.contains("<?") && root.contains("?>")) ||    // ignore <?xml ... ?> tag
           (root.contains("<!")))                             // ignore <! ... > tags (DTD and comments)
            return getXMLTree(lines,start+1);
        
        HashMap<String,String> attributes = getAttributes(root);
        String tag = getTagFromXML(root);
        ArrayList<XMLNode> children = new ArrayList<>(5);
        if (!root.contains("/>")) {
            lineIndex++;
            for (;lineIndex<lines.size();lineIndex++) {
                String current = lines.get(lineIndex);
                if (current.contains("</" + tag + ">")) {
                    break;
                }
                XMLElement n = getXMLTree(lines,lineIndex);
                if (n != null) {
                    children.add(n);
                }
            }
        } else {
            children = null;
        }
        return new XMLElement(tag,attributes,children);
        } catch (Exception e) {
            PowerGrid.logMessage("Error while parsing XML tree");
            return null;
        }
    }
}
