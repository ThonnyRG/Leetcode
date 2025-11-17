/*
 * @lc app=leetcode id=1437 lang=cpp
 *
 * [1437] Check If All 1's Are at Least Length K Places Away
 */

// @lc code=start
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
       int prevOneIndex = -(k + 1);
       int n = nums.size();

       for (int i = 0; i < n; i++)
       {
        if (nums[i] == 1)
        {
            if (i - prevOneIndex - 1 < k)
            {
                return false;
            }
            prevOneIndex = i;
            
        }
        
       }
       return true;
    }
};
// @lc code=end

