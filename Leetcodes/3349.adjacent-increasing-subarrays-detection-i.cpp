/*
 * @lc app=leetcode id=3349 lang=cpp
 *
 * [3349] Adjacent Increasing Subarrays Detection I
 */

// @lc code=start
// slightly modified
class Solution {
public:
    static bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        const int n=nums.size();
        int len=1, prev=0;
        for (int i=1; i<n && max(len/2, min(len, prev))<k; i++){
            if (nums[i]>nums[i-1]) len++; 
            else{
                prev=len;
                len=1;
            }
        }
        return max(len/2, min(len, prev))>=k;
        
    }
};
// @lc code=end

