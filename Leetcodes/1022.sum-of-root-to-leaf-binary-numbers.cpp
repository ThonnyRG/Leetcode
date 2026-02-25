/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        const int len = arr.size();
        vector<pair<int,int>>ones;
        for(int&num:arr){
            int number = num;
            int count = 0;
            while(number){
                if(number&1){++count;}
                number>>=1;
            }
            ones.push_back({count,num});
        }
        sort(ones.begin(),ones.end());
        for(int i=0;i<len;++i){
            arr[i]=ones[i].second;
        }
        return arr;
    }
};
// @lc code=end

