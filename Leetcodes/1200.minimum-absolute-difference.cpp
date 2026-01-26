/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        
        sort(arr.begin(),arr.end());
        int minDiff = abs(arr[0]-arr[1]);

        for (int i=0; i<arr.size()-1; i++) {
            int currDiff = abs(arr[i]-arr[i+1]);

            if (currDiff == minDiff) ans.push_back({arr[i],arr[i+1]});
            else if (currDiff<minDiff) {
                minDiff = currDiff;
                ans.clear();
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};
// @lc code=end
