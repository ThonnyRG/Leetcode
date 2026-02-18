/*
 * @lc app=leetcode id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
 */

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int cur = n % 2;
        n /= 2;
        while (n > 0)
        {
            if (cur == n % 2) return false;
                cur = n % 2;
                n /= 2;
        }
        return true;
    }
};
// @lc code=end

