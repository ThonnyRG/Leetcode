/*
 * @lc app=leetcode id=3041 lang=cpp
 *
 * [3041] Maximize Consecutive Elements in an Array After Modification
 */

// @lc code=start
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int ans = 0;
        for (int x : nums) {
            dp[x + 1] = max(dp[x + 1], dp[x] + 1);
            dp[x] = max(dp[x], dp[x - 1] + 1);
            ans = max(ans, max(dp[x], dp[x + 1]));
        }
        return ans;
    }
};
// @lc code=end

