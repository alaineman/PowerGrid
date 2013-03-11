package powergrid.model;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map.Entry;
import java.util.Objects;

/**
 * An XML node in an XML tree.
 * @author Chronio
 */
public class XMLElement extends XMLNode implements Iterable<XMLNode> {
    private String tag;
    private HashMap<String,String> attributes;
    private ArrayList<XMLNode> children;

    public XMLElement(String tag, HashMap<String, String> attributes, ArrayList<XMLNode> childs) {
        this.tag = tag;
        this.attributes = attributes;
        this.children = childs;
    }

    public XMLElement(String tag, HashMap<String,String> attributes) {
        this(tag,attributes,null);
    }
    
    /**
     * returns the tag of this XMLElement
     * @return the tag of this XMLElement
     */
    public String getTag() {
        return tag;
    }
    
    /**
     * returns a List of all XMLNodes that are direct childElements of this XMLElement 
     * and have the specified tag.
     * @param childTag the tag to look for
     * @return the List of all direct childElements of this XMLElement that have the desired tag
     */
    public ArrayList<XMLElement> getAll(String childTag) {
        if (children == null) return new ArrayList<>(1);
        ArrayList<XMLElement> res = new ArrayList<>(Math.max(10, children.size()));
        for (XMLElement n : childElements()) {
            if (n.getTag().equals(childTag))
                res.add(((XMLElement)n));
        }
        return res;
    }
    
    /**
     * returns whether this tag auto-closes or not. Auto-closing tags cannot have childElements
     * @return true if this XMLElement auto-closes, false otherwise
     */
    public boolean isSelfClosing() {
        return children == null;
    }
    
    /**
     * returns a List of all direct and indirect childElements of this XMLElement that have 
     * @param childTag the tag to look for
     * @return a List of XMLNodes with the desired tag
     */
    public ArrayList<XMLElement> getAllRecursive(String childTag) {
        if (isSelfClosing()) return new ArrayList<>(1);
        ArrayList<XMLElement> res = getAll(childTag);
        for (XMLElement n : childElements()) {
            res.addAll(n.getAllRecursive(childTag));
        }
        return res;
    }

    /**
     * returns a Map containing all the XMLElement's attributes and the respective values.
     * @return a Map containing the attributes and values
     */
    public HashMap<String, String> getAttributes() {
        return attributes;
    }

    /**
     * returns a list of the child elements of this XML Node.
     * <p/>
     * Text nodes are omitted here.
     * @return a list of the child elements of this XML Node
     */
    public ArrayList<XMLElement> childElements() {
        if (isSelfClosing()) 
            return new ArrayList<>(1);
        else {
            ArrayList<XMLElement> res = new ArrayList<>(children.size());
            for (XMLNode n : children) {
                if (n instanceof XMLElement) {
                    res.add((XMLElement)n);
                }
            }
            return res;
        }
    }
    
    /**
     * returns the value for the given attribute.
     * @param att the attribute to look up
     * @return the value for the attribute, or null if no such value exists
     */
    public String get(String att) {
        if (attributes == null) return null;
        return attributes.get(att);
    }
    
    public String getOrElse(String att, String orElse) {
        String val = get(att);
        if (val == null) return orElse;
        else return val;
    }
    
    /**
     * returns the XML for the XML tree with this Node as its root
     * @return a String-representation of this XML tree
     */
    @Override public String toString() {
        return toString("");
    }
    
    /**
     * helper method for toString() to build the XML String recursively.
     * @param prefix the prefix for each line of XML
     * @return the XML-tree for this XMLElement, where each line is prefixed with 
     *         the specified prefix
     */
    private String toString(String prefix) {
        String res = prefix + "<" + tag;
        if (attributes != null && !attributes.isEmpty()) {
            res += " ";
            for (Entry<String,String> att : attributes.entrySet()) {
                res += att.getKey() + "=\"" + att.getValue() + "\" ";
            }
        }
        if (isSelfClosing()) {
                res += "/>\n";
        } else {
            res += ">\n";
            for (XMLNode n : this) {
                if (n instanceof XMLElement)
                    res += ((XMLElement)n).toString(prefix + "  ");
                else if (n instanceof XMLText) 
                    res += prefix + "  " + ((XMLText)n).getText();
            }
            res += prefix + "</" + tag + ">\n";
        }
        return res;
    }

    @Override public int hashCode() {
        int hash = 7;
        hash = 79 * hash + Objects.hashCode(this.tag);
        hash = 79 * hash + Objects.hashCode(this.attributes);
        hash = 79 * hash + Objects.hashCode(this.children);
        return hash;
    }
    
    @Override public boolean equals(Object other) {
        if (other instanceof XMLElement) {
            XMLElement that = (XMLElement)other;
            if (!this.getTag().equals(that.getTag())) return false;
            if (!this.getAttributes().equals(that.getAttributes())) return false;
            
            if (!this.childElements().containsAll(that.childElements())) return false;
            if (!that.childElements().containsAll(this.childElements())) return false;
            
            return true;
        }
        return false;
    }
    
    public String set(String att, String val) {
        if (attributes == null) attributes = new HashMap<>(6);
        return attributes.put(att, val);
}

    @Override public Iterator<XMLNode> iterator() {
        return new XMLIterator();
    }
    
    public class XMLIterator implements Iterator<XMLNode> {

        private int position = 0;
        
        @Override public boolean hasNext() {
            return children.size() > position;
        }

        @Override public XMLNode next() {
            XMLNode next = children.get(position);
            position++;
            return next;
        }

        @Override public void remove() {
            throw new UnsupportedOperationException("Not supported.");
        }
    }
}
