/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int m = 1;
        int n = digits.size() - 1;
        
        while (m && n >= 0) {
            digits[n] += m;
            m = digits[n] / 10;
            digits[n] %= 10;
            n--;
        }
        
        if (m) {
            digits.insert(digits.begin(), m);
        }
        
        return digits;
    }
};
// @lc code=end

