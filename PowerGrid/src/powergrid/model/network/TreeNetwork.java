package powergrid.model.network;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * This class represents a network of Transport Tiles where the Tiles 
 * and the links between them act as a tree.
 * <p/>
 * This network type is preferred when the layout is like a tree, since the 
 * findPath method runs in O(n) and uses less memory than most pathfinding algorithms.
 * <p/>
 * @author Chronio
 */
public class TreeNetwork implements TransportNetwork {

    private TreeNode<NetworkElement> root = null;
    
    /**
     * Creates a new TreeNetwork with the given element as root.
     * @param rootElement the root of the TreeNetwork
     */
    public TreeNetwork(NetworkElement rootElement) {
        root = new TreeNode<>(rootElement);
    }
    
    /**
     * Creates a connections between two transportables, 
     * adding the child to the parent's child nodes.
     * <p/>
     * This possibly overwrites an existing parent-child relation, since 
     * TreeNodes can only have one parent.
     * <p/>
     * @param parent the parent TransportTile
     * @param child the child TransportTile
     * @return whether the operation was successful.
     */
    public boolean makeConnection(NetworkElement parent, NetworkElement child) {
        TreeNode<NetworkElement> pNode = root.find(parent);
        if (pNode != null) {
            TreeNode<NetworkElement> cNode = root.find(child);
            if (cNode == null) cNode = new TreeNode<>(child);
            pNode.addChild(cNode);
            return true;
        } else
            return false;
    }
    
    /**
     * Returns the root TreeNode of this TreeNetwork
     * @return this TreeNetwork's root
     */
    public TreeNode<NetworkElement> getRoot() {
        return root;
    }
    
    /**
     * Returns whether the Tree contains the given element.
     * @param element the element to find
     * @return whether the Tree contains the given element.
     */
    @Override public boolean contains(NetworkElement element) {
        return root.contains(element);
    }

    /**
     * Adds the given TransportTile to this TreeNode's root if and only if the 
     * Tree did not yet contain the given TransportTile
     * @param element the element to add
     * @return whether the element was created and added to the root.
     */
    @Override public boolean add(NetworkElement element) {
        if (root.find(element) != null) return false;
        else return (root.add(element) != null);
    }

    /**
     * Removes the specified element from this Tree
     * @param element the element to remove
     * @return true if the operation was successful
     */
    @Override public boolean remove(NetworkElement element) {
        TreeNode<NetworkElement> node = root.find(element);
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
     * Computes a path between the given source and destination by navigating 
     * upwards through the Tree until the source and destination share a common 
     * parent.
     * <p/>
     * This method runs in O(n) (where <code>n = size()</code>).
     * @param source the starting point
     * @param destination the end point
     * @return the path through the tree between source and destination
     */
    @Override public List<NetworkElement> findPath(NetworkElement source, NetworkElement destination) {
        TreeNode<NetworkElement> sNode = root.find(source);
        TreeNode<NetworkElement> dNode = root.find(destination);
        if (sNode == null || dNode == null) return null;
        List<TreeNode<NetworkElement>> sList = sNode.parents();
        List<TreeNode<NetworkElement>> dList = dNode.parents();
        int dSize = dList.size();
        int sSize = sList.size();
        TreeNode<NetworkElement> commonNode = root;
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
        ArrayList<NetworkElement> result = new ArrayList<>(sList.size());
        for (TreeNode<NetworkElement> tn : sList) {
            result.add(tn.element());
        }
        result.add(destination);
        return result;
    }
    
    @Override public Set<NetworkElement> getElements() {
        Set<TreeNode<NetworkElement>> nodes = getRoot().allChildren();
        HashSet<NetworkElement> elems = new HashSet<>(nodes.size());
        for (TreeNode<NetworkElement> node : nodes) {
            elems.add(node.element());
        }
        return elems;
    }
}
