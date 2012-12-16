package powerwalk.model;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * 
 * @author P.Kramer
 */
public class XMLNode {
    private String tag;
    private HashMap<String,String> attributes;
    private ArrayList<XMLNode> childs;

    public XMLNode(String tag, HashMap<String, String> attributes, ArrayList<XMLNode> childs) {
        this.tag = tag;
        this.attributes = attributes;
        this.childs = childs;
    }

    public String getTag() {
        return tag;
    }

    public HashMap<String, String> getAttributes() {
        return attributes;
    }

    public ArrayList<XMLNode> children() {
        return childs;
    }
    
    public String get(String att) {
        return attributes.get(att);
    }
}
