/*
 * @lc app=leetcode id=2221 lang=cpp
 *
 * [2221] Find Triangular Sum of an Array
 */

// @lc code=start
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = n-2;i>=0;i--){
            for(int j = 0;j<=i;j++){
                nums[j] = (nums[j] + nums[j+1]) % 10;
            }
        }
        return nums[0];
    }
};
// @lc code=end

