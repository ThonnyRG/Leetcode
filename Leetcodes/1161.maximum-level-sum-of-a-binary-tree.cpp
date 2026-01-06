/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);

        int maxSum = INT_MIN;
        int levelWithMaxSum = 0;
        int currentLevel = 0;

        while (!bfsQueue.empty())
        {
            currentLevel++;
            int currentLevelSum = 0;
            int nodesInCurrentLevel = bfsQueue.size();

            for (int i = 0; i < nodesInCurrentLevel; i++)
            {
                TreeNode *currentNode = bfsQueue.front();
                bfsQueue.pop();
                currentLevelSum += currentNode->val;

                if (currentNode->left != nullptr)
                {
                    bfsQueue.push(currentNode->left);
                }
                if (currentNode->right != nullptr)
                {
                    bfsQueue.push(currentNode->right);
                }
            }
            if (currentLevelSum > maxSum)
            {
                maxSum = currentLevelSum;
                levelWithMaxSum = currentLevel;
            }
        }
        return levelWithMaxSum;
    }
};
// @lc code=end
