/*
 * @lc app=leetcode id=3354 lang=cpp
 *
 * [3354] Make Array Elements Equal to Zero
 */

// @lc code=start
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        int validCount = 0;
        int leftSum = 0;

        for (int currentNum: nums)
        {
            if (currentNum != 0)
            {
                leftSum += currentNum;
            }else{
                int rightSum = totalSum - leftSum;

                if (leftSum == rightSum)
                {
                    validCount += 2;
                }else if (abs (leftSum - rightSum) == 1)
                {
                    validCount++;
                }
                
                
            }
            
        }
        return validCount;
    }
};
// @lc code=end

