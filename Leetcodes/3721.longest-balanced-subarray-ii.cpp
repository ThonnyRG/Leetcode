/*
 * @lc app=leetcode id=3721 lang=cpp
 *
 * [3721] Longest Balanced Subarray II
 */

// @lc code=start
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = (int)nums.size();

        vector<int> balance(n, 0); 
        unordered_map<int, int> first; 

        int result = 0;

        for (int l = n - 1; l >= 0; --l) {
            int x = nums[l];

            auto it = first.find(x);
            if (it != first.end())
                balance[it->second] = 0;

            first[x] = l;
            balance[l] = ((x & 1) == 0) ? 1 : -1;

            int s = 0;
            for (int r = l; r < n; ++r) {
                s += balance[r];
                if (s == 0)
                    result = max(result, r - l + 1);
            }
        }

        return result;
    }
};
// @lc code=end

