/*
 * @lc app=leetcode id=1385 lang=cpp
 *
 * [1385] Find the Distance Value Between Two Arrays
 */

// @lc code=start
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for (auto& x : arr1) {
            bool ok = true;
            for (auto& y : arr2) {
                ok &= (abs(x - y) > d);
            }
            cnt += ok;
        }
        return cnt;
    }
};
// @lc code=end

