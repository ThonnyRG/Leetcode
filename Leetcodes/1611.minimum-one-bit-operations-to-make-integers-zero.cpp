/*
 * @lc app=leetcode id=1611 lang=cpp
 *
 * [1611] Minimum One Bit Operations to Make Integers Zero
 */

// @lc code=start
class Solution {
public:
    int minimumOneBitOperations(int n) {
       int multipler = 1;
       int res = 0;

       while (n > 0)
       {
        res += n ^ (n - 1) * multipler;
        multipler = -1 * multipler;
        n &= n -1;
       }
      return abs(res);
    }
};
// @lc code=end

