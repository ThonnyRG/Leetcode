package Leetcodes;
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        
        if(depth == 1){
            return new TreeNode(val,root,null);
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int currDepth = 1;
        while(currDepth < depth - 1){

             Queue<TreeNode> tempQueue = new LinkedList<>();
             while(!queue.isEmpty()){
                TreeNode currNode = queue.remove();
                if(currNode.left != null) tempQueue.add(currNode.left);
                if(currNode.right != null) tempQueue.add(currNode.right);
             }
             queue = tempQueue;
             currDepth++;
        }

        while(!queue.isEmpty()){
            TreeNode currNode = queue.remove();
            currNode.left = new TreeNode(val,currNode.left,null);
            currNode.right = new TreeNode(val,null,currNode.right);

        }
        return root;
    }
}