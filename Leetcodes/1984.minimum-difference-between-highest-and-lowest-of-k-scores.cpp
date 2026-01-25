/*
 * @lc app=leetcode id=1984 lang=cpp
 *
 * [1984] Minimum Difference Between Highest and Lowest of K Scores
 */

// @lc code=start
class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        int n = nums.size();

        if (k > 1)
        {
            sort(nums.begin(), nums.end());
            int ans = INT_MAX;
            for (int i = 0; i + k - 1 < n; ++i)
            {
                ans = min(ans, nums[i + k - 1] - nums[i]);
            }
            return ans;
        }
        return 0;
    }
};
// @lc code=end
