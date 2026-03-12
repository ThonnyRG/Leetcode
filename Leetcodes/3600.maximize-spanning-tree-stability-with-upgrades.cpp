/*
 * @lc app=leetcode id=3600 lang=cpp
 *
 * [3600] Maximize Spanning Tree Stability with Upgrades
 */

// @lc code=start
class Solution
{
public:
    int maxStability(int n, vector<vector<int>> &edges, int k)
    {
        int right = 0;
        for (auto &e : edges)
            right = max(right, e[2]);
        right *= 2;
        int left = -1;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (check(mid))
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};
// @lc code=end
