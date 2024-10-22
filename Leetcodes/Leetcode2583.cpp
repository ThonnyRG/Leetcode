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
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        priority_queue<long long> p;
        while(!q.empty()){
            int n = q.size();
            long long sum = 0;
            for(int i = 0; i < n; i++){
                TreeNode* curr = q.front();
                q.pop();
                sum += (curr->val);
                if(curr -> left != nullptr){
                    q.push(curr -> left);
                }
                if(curr -> right != nullptr){
                    q.push(curr -> right);
                }
            }
            p.push(sum);
        }
        if(p.size()<k){
            return -1;
        }
        k--;
        while(k--){
            p.pop();
        }
        return p.top();
    }
};