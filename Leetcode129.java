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
    public int sumNumbers(TreeNode root) {
        return REC(root, 0);
    }
    
    private int REC(TreeNode node, int total) {
        if (node != null) {
            total = total * 10 + node.val;

            if (node.left == null && node.right == null) {
                return total;
            }
            
            int leftSum = REC(node.left, total);
            int rightSum = REC(node.right, total);
            
            return leftSum + rightSum;
        } else {
            return 0;
        }
    }
}
