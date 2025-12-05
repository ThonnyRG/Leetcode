/*
 * @lc app=leetcode id=3432 lang=cpp
 *
 * [3432] Count Partitions with Even Sum Difference
 */

// @lc code=start
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();

        int partitionCount = 0;

        for (int i = 0; i < n - 1; ++i)
        {
            leftSum += nums[i];
            rightSum -= nus[i];

            if ((leftSum - rightSum) % 2 == 0)
            {
                ++partitionCount;
            }
            
        }
        return partitionCount;
    }
};
// @lc code=end

