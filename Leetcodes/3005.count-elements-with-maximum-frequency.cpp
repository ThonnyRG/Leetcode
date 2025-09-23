/*
 * @lc app=leetcode id=3005 lang=cpp
 *
 * [3005] Count Elements With Maximum Frequency
 */

// @lc code=start
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int max_freq = 0;
        unordered_map<int, int> mp;
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]] == max_freq) count += max_freq;
            else if(mp[nums[i]] > max_freq){
                max_freq = mp[nums[i]];
                count = max_freq;
            } 
        }
        return count;
    }
};
// @lc code=end

