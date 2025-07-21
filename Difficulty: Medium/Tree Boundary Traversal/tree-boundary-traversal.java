/*
class Node
{
    int data;
    Node left, right;

    public Node(int d)
    {
        data = d;
        left = right = null;
    }
}
*/

class Solution {
    boolean isLeaf(Node root){
        return (root.left==null && root.right==null);
    }
    void addLeftBoundary(Node root, ArrayList<Integer> ans){
        Node curr = root.left;
        while(curr != null){
            if(isLeaf(curr) == false) ans.add(curr.data);
            if(curr.left != null) curr=curr.left;
            else curr=curr.right;
        }
    }
    void addRightBoundary(Node root, ArrayList<Integer>res){
        Node curr=root.right;
        ArrayList<Integer>tmp = new ArrayList<Integer>();
        while(curr != null){
            if(isLeaf(curr)== false) tmp.add(curr.data);
            if(curr.right !=null) curr=curr.right;
            else curr=curr.left;
        }
        for(int i=tmp.size()-1;i>=0;i--){
            res.add(tmp.get(i));
        }
    }
    void addLeaves(Node root, ArrayList<Integer>res){
        if(isLeaf(root)){
            res.add(root.data);
            return;
        }
        if(root.left!=null) addLeaves(root.left,res);
        if(root.right !=null) addLeaves(root.right, res);
    }
    ArrayList<Integer> boundaryTraversal(Node node) {
        // code here
        ArrayList<Integer>ans = new ArrayList<Integer>();
        if(isLeaf(node) == false) ans.add(node.data);
        addLeftBoundary(node, ans);
        addLeaves(node, ans);
        addRightBoundary(node, ans);
        return ans; 
    }
}