/*
 * @lc app=leetcode id=3289 lang=cpp
 *
 * [3289] The Two Sneaky Numbers of Digitville
 */

// @lc code=start
class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (mp[nums[i]] > 1)
            {
                ans.push_back(nums[i]);
                mp[nums[i]] = -1;
            }
            
        }
        return ans;
    }
};
// @lc code=end
