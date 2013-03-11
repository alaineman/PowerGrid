package powergrid.model;

/**
 * Represents a text node in a XML tree
 * @author Chronio
 */
public class XMLText extends XMLNode {
    private String text;
    
    public XMLText(String text) {
        this.text = text;
    }
    
    public String getText() {
        return text;
    }
}
