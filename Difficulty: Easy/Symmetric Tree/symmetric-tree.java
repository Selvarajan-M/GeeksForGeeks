/*
class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}

*/
class Solution {
    public boolean isSymmetric(Node root) {
        // Code here
        return root == null || isSymmetricHelper(root.left,root.right);
    }
    private boolean isSymmetricHelper(Node left, Node right){
        if(left==null || right==null)
        return left==right;
        if(left.data != right.data) return false;
        return isSymmetricHelper(left.left,right.right) && isSymmetricHelper(left.right,right.left);
    }
}