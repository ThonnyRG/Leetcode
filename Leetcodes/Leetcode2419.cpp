class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int length = 0;
        int maxVal = 0;

        // 1st loop to find the maximum value
        for(int i = 0; i < nums.size(); i++) {
            maxVal = max(maxVal, nums[i]);
        }

        // 2nd loop to find the longest contiguous subarray of the maximum value
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == maxVal) {
                count++;
                length = max(length, count);
            } else {
                count = 0;
            }
        }

        return length;
    }
};