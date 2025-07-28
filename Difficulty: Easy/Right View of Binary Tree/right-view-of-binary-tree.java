/*Complete The Function Provided
Given Below is The Node Of Tree
class Node
{
    int data;
    Node left, right;
    public Node(int data)
    {
        this.data = data;
         left = right = null;
    }
}*/

class Solution {
    // Function to return list containing elements of right view of binary tree.
    public void recursion(Node root, int level, ArrayList<Integer>ans){
        if(root == null){
            return;
        }
        if(level == ans.size()){
            ans.add(root.data);
        }
        recursion(root.right,level+1,ans);
        recursion(root.left,level+1,ans);
    }
    ArrayList<Integer> rightView(Node root) {
        // add code here.
        ArrayList<Integer>ans= new ArrayList<>();
        recursion(root,0,ans);
        return ans;
    }
}