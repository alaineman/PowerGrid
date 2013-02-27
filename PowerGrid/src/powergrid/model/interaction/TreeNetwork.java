package powergrid.model.interaction;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import powergrid.model.interact.Transportable;

/**
 *
 * @author Chronio
 */
public class TreeNetwork implements TransportNetwork<Transportable> {

    private TreeNode<Transportable> root = null;
    
    public TreeNetwork(Transportable rootElement) {
        root = new TreeNode<>(rootElement);
    }
    
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
    
    public TreeNode<Transportable> getRoot() {
        return root;
    }
    
    @Override public boolean contains(Transportable element) {
        return root.contains(element);
    }

    @Override public boolean add(Transportable element) {
        if (root.find(element) != null) return false;
        else return (root.add(element) != null);
    }

    @Override public boolean remove(Transportable element) {
        TreeNode<Transportable> node = root.find(element);
        if (node == null || !node.hasParent()) 
            return false;
        return node.getParent().removeChild(node);
    }

    @Override public int size() {
        return root.size();
    }

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
        return result;
    }
    
}
