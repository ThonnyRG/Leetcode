/*
 * @lc app=leetcode id=3719 lang=cpp
 *
 * [3719] Longest Balanced Subarray I
 */

// @lc code=start
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<uint16_t> seen(maxVal + 1, 0);
        
        for (int i = 0; i < n; i++) {
            int A[2] = {0, 0};
            
            for (int j = i; j < n; j++) {
                int val = nums[j];
                if (seen[val] != i + 1) {
                    seen[val] = i + 1;
                    A[val & 1]++;
                }
                
                if (A[0] == A[1])
                    res = max(res, j - i + 1);
            }
        }
        
        return res;
    }
};
// @lc code=end

