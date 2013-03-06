package powergrid.model.interaction;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import powergrid.model.interact.Transportable;

/**
 * This class represents a network of Transportables where the Transportables 
 * and the links between them act as a tree.
 * <p/>
 * This network type is preferred when the layout is like a tree, since the 
 * findPath method runs in O(n) and uses less memory than most pathfinding algorithms.
 * <p/>
 * @author Chronio
 */
public class TreeNetwork implements TransportNetwork {

    private TreeNode<Transportable> root = null;
    
    /**
     * Creates a new TreeNetwork with the given element as root.
     * @param rootElement the root of the TreeNetwork
     */
    public TreeNetwork(Transportable rootElement) {
        root = new TreeNode<>(rootElement);
    }
    
    /**
     * Creates a connections between two transportables, 
     * adding the child to the parent's child nodes.
     * <p/>
     * This possibly overwrites an existing parent-child relation, since 
     * TreeNodes can only have one parent.
     * <p/>
     * @param parent the parent Transportable
     * @param child the child Transportable
     * @return whether the operation was succesful.
     */
    public boolean makeConnection(Transportable parent, Transportable child) {
        TreeNode<Transportable> pNode = root.find(parent);
        if (pNode != null) {
            TreeNode<Transportable> cNode = root.find(child);
            if (cNode == null) cNode = new TreeNode(child);
            pNode.addChild(cNode);
            return true;
        } else
            return false;
    }
    
    /**
     * Returns the root TreeNode of this TreeNetwork
     * @return this TreeNetwork's root
     */
    public TreeNode<Transportable> getRoot() {
        return root;
    }
    
    /**
     * Returns whether the Tree contains the given element.
     * @param element the element to find
     * @return whether the Tree contains the given element.
     */
    @Override public boolean contains(Transportable element) {
        return root.contains(element);
    }

    /**
     * Adds the given Transportable to this TreeNode's root if and only if the 
     * Tree did not yet contain the given Transportable
     * @param element the element to add
     * @return whether the element was created and added to the root.
     */
    @Override public boolean add(Transportable element) {
        if (root.find(element) != null) return false;
        else return (root.add(element) != null);
    }

    /**
     * Removes the specified element from this Tree
     * @param element the element to remove
     * @return true if the operation was succesful
     */
    @Override public boolean remove(Transportable element) {
        TreeNode<Transportable> node = root.find(element);
        if (node == null || !node.hasParent()) 
            return false;
        return node.getParent().removeChild(node);
    }

    /**
     * Returns the amount of Nodes in the Tree.
     * @return the amount of Nodes in the Tree
     */
    @Override public int size() {
        return root.size();
    }

    /**
     * Computes a path between the given source and destination by nagivating 
     * upwards through the Tree until the source and destination share a common 
     * parent.
     * <p/>
     * This method runs in O(n) (where <code>n = size()</code>).
     * @param source the starting point
     * @param destination the end point
     * @return the path through the tree between source and destination
     */
    @Override public List<Transportable> findPath(Transportable source, Transportable destination) {
        TreeNode<Transportable> sNode = root.find(source);
        TreeNode<Transportable> dNode = root.find(destination);
        if (sNode == null || dNode == null) return null;
        List<TreeNode<Transportable>> sList = sNode.parents();
        List<TreeNode<Transportable>> dList = dNode.parents();
        int dSize = dList.size();
        int sSize = sList.size();
        TreeNode<Transportable> commonNode = root;
        for (int i=1;i<=Math.min(sSize, dSize);i++) {
            if (dList.get(dSize-i).equals(sList.get(sSize-i))) {
                commonNode = dList.get(dSize-i);
                dList.remove(dSize-i);
                sList.remove(sSize-i);
            } else {
                break;
            }
        }
        sList.add(commonNode);
        Collections.reverse(dList);
        sList.addAll(dList);
        ArrayList<Transportable> result = new ArrayList<>(sList.size());
        for (TreeNode<Transportable> tn : sList) {
            result.add(tn.element());
        }
        result.add(destination);
        return result;
    }
    
}
