/*
 * @lc app=leetcode id=1304 lang=cpp
 *
 * [1304] Find N Unique Integers Sum up to Zero
 */

// @lc code=start
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n);
       int index = 0;
       for (int i = 1; i <= n / 2; ++i)
       {
            result[index++] = i;
            result[index++] = -i;
       }
       return result;
    }
};
// @lc code=end

