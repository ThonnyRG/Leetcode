/*
 * @lc app=leetcode id=3623 lang=cpp
 *
 * [3623] Count Number of Trapezoids I
 */

// @lc code=start
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int MOD = 1000000007;
        unordered_map<int, long long> groups;
        for (auto& point : points)
            groups[point[1]]++;
        long long res = 0, total = 0;
        for (auto& group : groups){
            long long lines = group.second * (group.second - 1) / 2;
            res = (res + total * lines) % MOD;
            total = (total + lines) % MOD;
        }
        return (int)res;
    }
};
// @lc code=end

