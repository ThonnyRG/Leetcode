/*
 * @lc app=leetcode id=2598 lang=cpp
 *
 * [2598] Smallest Missing Non-negative Integer After Operations
 */

// @lc code=start
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> rests(value, 0);
        int mini = nums.size();
        for (int num : nums) {
            if (num >= 0 || num % value == 0)
                rests[num % value]++;
            else
                rests[value - (abs(num) % value)]++;
        }

        for (int i = 0; i < value; i++) {
            mini = min(mini, rests[i] * value + i);
        }

        return mini;
    }
};
// @lc code=end

