/*
 * @lc app=leetcode id=2913 lang=cpp
 *
 * [2913] Subarrays Distinct Element Sum of Squares I
 */

// @lc code=start
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> s;
            for (int j = i; j < n; j++) {
                s.insert(nums[j]);
                res += s.size() * s.size();
            }
        }
        return res;
    }
};
// @lc code=end

