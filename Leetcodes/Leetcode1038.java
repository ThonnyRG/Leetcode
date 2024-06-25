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
    int sum = 0;
  
    private void inOrder(TreeNode node) {
      if (node == null) return;
  
      inOrder(node.right);
  
      sum += node.val;
      node.val = sum;
  
      inOrder(node.left);
    }
  
    public TreeNode bstToGst(TreeNode root) {
      inOrder(root);
      return root;
    }
  }