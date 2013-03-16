package powergrid.model.interaction.network;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Set;
import powergrid.model.interaction.TransportTile;

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

    private TreeNode<TransportTile> root = null;
    
    /**
     * Creates a new TreeNetwork with the given element as root.
     * @param rootElement the root of the TreeNetwork
     */
    public TreeNetwork(TransportTile rootElement) {
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
     * @return whether the operation was succesful.
     */
    public boolean makeConnection(TransportTile parent, TransportTile child) {
        TreeNode<TransportTile> pNode = root.find(parent);
        if (pNode != null) {
            TreeNode<TransportTile> cNode = root.find(child);
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
    public TreeNode<TransportTile> getRoot() {
        return root;
    }
    
    /**
     * Returns whether the Tree contains the given element.
     * @param element the element to find
     * @return whether the Tree contains the given element.
     */
    @Override public boolean contains(TransportTile element) {
        return root.contains(element);
    }

    /**
     * Adds the given TransportTile to this TreeNode's root if and only if the 
     * Tree did not yet contain the given TransportTile
     * @param element the element to add
     * @return whether the element was created and added to the root.
     */
    @Override public boolean add(TransportTile element) {
        if (root.find(element) != null) return false;
        else return (root.add(element) != null);
    }

    /**
     * Removes the specified element from this Tree
     * @param element the element to remove
     * @return true if the operation was succesful
     */
    @Override public boolean remove(TransportTile element) {
        TreeNode<TransportTile> node = root.find(element);
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
    @Override public List<TransportTile> findPath(TransportTile source, TransportTile destination) {
        TreeNode<TransportTile> sNode = root.find(source);
        TreeNode<TransportTile> dNode = root.find(destination);
        if (sNode == null || dNode == null) return null;
        List<TreeNode<TransportTile>> sList = sNode.parents();
        List<TreeNode<TransportTile>> dList = dNode.parents();
        int dSize = dList.size();
        int sSize = sList.size();
        TreeNode<TransportTile> commonNode = root;
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
        ArrayList<TransportTile> result = new ArrayList<>(sList.size());
        for (TreeNode<TransportTile> tn : sList) {
            result.add(tn.element());
        }
        result.add(destination);
        return result;
    }
    
    @Override public Set<TransportTile> getElements() {
        return null;
    }
}
