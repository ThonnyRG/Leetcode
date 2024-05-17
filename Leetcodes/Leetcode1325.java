/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        if (root == null) {
            // If the current node is null, return null
            return null;
        }

        // Recursively process the left subtree
        root.left = removeLeafNodes(root.left, target);
        // Recursively process the right subtree
        root.right = removeLeafNodes(root.right, target);

        // Check if the current node is a leaf node with the target value
        if (root.left == null && root.right == null && root.val == target) {
            // If true, return null to remove this node
            return null;
        }

        // If the current node is not a target leaf node, return the current node
        return root;
    }
}