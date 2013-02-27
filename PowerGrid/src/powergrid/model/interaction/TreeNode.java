package powergrid.model.interaction;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

/**
 * This class represents a Node in a Tree. 
 * <p/>
 * 
 * @author Chronio
 */
public class TreeNode<T> {
    private TreeNode<T> parent = null;
    private T element;
    private HashSet<TreeNode<T>> children;
    
    public TreeNode(T element) {
        this.element = element;
        this.children = new HashSet<>(8);
    }
    
    public T element() {
        return element;
    }
    
    public T setElement(T element) {
        T elem = this.element;
        this.element = element;
        return elem;
    }
    
    public TreeNode<T> getParent() {
        return parent;
    }
    
    private TreeNode<T> setParent(TreeNode<T> node) {
        TreeNode p = parent;
        parent = node;
        return p;
    }
    
    public boolean contains(T element) {
        return find(element) != null;
    }
    
    public TreeNode<T> find(T element) {
        if (element == null)
            if (this.element == null) return this;
        for (TreeNode<T> tn : children) {
            TreeNode<T> node = tn.find(element);
            if (node != null) return node;
        }
        return null;
    }
    
    public int size() {
        int s = 1;
        for (TreeNode<T> node : children) {
            s += node.size();
        }
        return s;
    }
    
    public boolean hasParent() {
        return parent != null;
    }
    
    public boolean containsChild(TreeNode<T> node) {
        return children.contains(node);
    }
    
    public TreeNode<T> add(T element) {
        TreeNode node = new TreeNode(element);
        addChild(node);
        return node;
    }
    
    public boolean addChild(TreeNode<T> node) {
        if (node == null) return false;
        if (parents().contains(node))
            throw new IllegalArgumentException("This will create a loop of parents.");
        if (node.hasParent()) 
            node.getParent().removeChild(node);
        node.setParent(this);
        return children.add(node);
    }
    
    public int depth() {
        if (parent == null) return 0;
        else return parent.depth() + 1;
    }
    
    public List<TreeNode<T>> parents() {
        ArrayList<TreeNode<T>> list = new ArrayList<>();
        TreeNode<T> node = getParent();
        while (node != null) {
            list.add(node);
            node = node.getParent();
        }
        return list;
    }
    
    public TreeNode<T> getRoot() {
        TreeNode<T> node = this;
        while (node.getParent() != null) {
            node = node.getParent();
        } 
        return node;
    }
    
    public boolean removeChild(TreeNode<T> node) {
        if (children.contains(node)) {
            node.setParent(null);
            return children.remove(node);
        } else 
            return false;
    }
    
    public HashSet<TreeNode<T>> children() {
        return new HashSet<>(children);
    }
}
