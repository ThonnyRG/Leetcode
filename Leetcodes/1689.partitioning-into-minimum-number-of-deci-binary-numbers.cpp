/*
 * @lc app=leetcode id=1689 lang=cpp
 *
 * [1689] Partitioning Into Minimum Number Of Deci-Binary Numbers
 */

// @lc code=start
class Solution {
public:
    static int minPartitions(string& n) {
        int ans=0;
        for(int x: n){
            ans=max(ans, x-'0');
            if (ans==9) break;
        }
        return ans;
    }
};
// @lc code=end

