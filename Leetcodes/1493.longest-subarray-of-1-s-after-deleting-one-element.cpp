/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int st=0,end=0;
        int ans = INT_MIN;
        int cntzero = 0;
        while(end < nums.size())
        {
            if(nums[end] == 0) cntzero++;
            while(cntzero > 1)
            {
                if(nums[st] == 0)
                {
                    cntzero--;
                }
                st++;
            }
            ans = max(ans,end-st);
            end++;
        }
        return ans;
    }
};
// @lc code=end

