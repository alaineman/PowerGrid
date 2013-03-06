package powergrid.model.interaction;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

/**
 * This class represents a Node in a Tree. 
 * <p/>
 * It features multiple search and contains methods, as well as basic add and 
 * remove operations.
 * <p/>
 * @author Chronio
 */
public class TreeNode<T> {
    private TreeNode<T> parent = null;
    private T element;
    private HashSet<TreeNode<T>> children;
    
    /**
     * Constructs a new TreeNode with the specified element.
     * <p/>
     * The constructed TreeNode will behave as the root of a Tree with only one 
     * Node until more nodes are added, or this TreeNode is added to an existing Tree.
     * @param element the element of this node
     */
    public TreeNode(T element) {
        this.element = element;
        this.children = new HashSet<>(8);
    }
    
    /**
     * Returns the element in this TreeNode
     * @return the element in this TreeNode
     */
    public T element() {
        return element;
    }
    
    /**
     * Sets the element in this TreeNode
     * @param element the new element, can be null
     * @return the old element
     */
    public T setElement(T element) {
        T elem = this.element;
        this.element = element;
        return elem;
    }
    
    /**
     * Returns the TreeNode's parent Node, or null if this TreeNode is the root.
     * @return the TreeNode's parent
     */
    public TreeNode<T> getParent() {
        return parent;
    }
    
    /**
     * private method that sets the Node's parent after changing the Tree's structure.
     * @param node the new parent
     * @return the old parent.
     */
    private TreeNode<T> setParent(TreeNode<T> node) {
        TreeNode p = parent;
        parent = node;
        return p;
    }
    
    /**
     * Returns whether or not the subtree with this Node as root contains the given element.
     * @param element the element to find.
     * @return whether the element was found in the subtree
     */
    public boolean contains(T element) {
        return find(element) != null;
    }
    
    /**
     * Finds the TreeNode associated with a particular element using depth-first search.
     * <p/>
     * If the element occurs multiple times, the first occurance of a TreeNode 
     * with the element is returned according to the order dictated by 
     * depth-first search.
     * <p/>
     * @param element the element to find
     * @return the TreeNode that contains this element
     */
    public TreeNode<T> find(T element) {
        if (element == null)
            if (this.element == null) return this;
        for (TreeNode<T> tn : children) {
            TreeNode<T> node = tn.find(element);
            if (node != null) return node;
        }
        return null;
    }
    
    /**
     * Computes and returns the amount of nodes in this (sub)tree.
     * @return the amount of nodes in the (sub)tree.
     */
    public int size() {
        int s = 1;
        for (TreeNode<T> node : children) {
            s += node.size();
        }
        return s;
    }
    
    /**
     * Returns whether this TreeNode has a parent.
     * <p/>
     * If a TreeNode has no parent, it means the TreeNode is the root of a Tree.
     * @return The TreeNode's parent
     */
    public boolean hasParent() {
        return parent != null;
    }
    
    /**
     * Returns whether the given TreeNode is a direct child of this Node.
     * @param node the node to check
     * @return true if the TreeNode is a child of this TreeNode, false otherwise
     */
    public boolean containsChild(TreeNode<T> node) {
        return children.contains(node);
    }
    
    /**
     * Adds the given element as a child node to this TreeNode.
     * @param element the element to add
     * @return the created TreeNode
     */
    public TreeNode<T> add(T element) {
        TreeNode node = new TreeNode(element);
        addChild(node);
        return node;
    }
    
    /**
     * Adds the given TreeNode to this TreeNode as a child. 
     * <p/>
     * The TreeNode's previous parent will be overridden.
     * @param node the Node to add
     * @return whether the opeation was succesful
     */
    public boolean addChild(TreeNode<T> node) {
        if (node == null) return false;
        if (parents().contains(node))
            throw new IllegalArgumentException("This will create a loop of parents.");
        if (node.hasParent()) 
            node.getParent().removeChild(node);
        node.setParent(this);
        return children.add(node);
    }
    
    /**
     * Returns the depth of this (sub)tree.
     * @return the depth of this (sub)tree.
     */
    public int depth() {
        if (parent == null) return 0;
        else return parent.depth() + 1;
    }
    
    /**
     * Returns a bottom-up List of the TreeNode's parents.
     * <p/>
     * The returned List represents a path of TreeNodes that leads to the root 
     * of this tree.
     * @return the List of all parents (bottom-up) of this TreeNode.
     */
    public List<TreeNode<T>> parents() {
        ArrayList<TreeNode<T>> list = new ArrayList<>();
        TreeNode<T> node = getParent();
        while (node != null) {
            list.add(node);
            node = node.getParent();
        }
        return list;
    }
    
    /**
     * Returns the root of the Tree this TreeNode is part of
     * @return the root of the Tree this TreeNode is part of
     */
    public TreeNode<T> getRoot() {
        TreeNode<T> node = this;
        while (node.getParent() != null) {
            node = node.getParent();
        } 
        return node;
    }
    
    /**
     * Removes the specified Node from this TreeNode
     * @param node the TreeNode to remove
     * @return whether this TreeNode contained the given node as a child and it is succedfully removed.
     */
    public boolean removeChild(TreeNode<T> node) {
        if (children.contains(node)) {
            node.setParent(null);
            return children.remove(node);
        } else 
            return false;
    }
    
    /**
     * Returns a Set of TreeNodes that are the direct children of this TreeNode.
     * @return the Set of children in this TreeNode.
     */
    public HashSet<TreeNode<T>> children() {
        return new HashSet<>(children);
    }
}
