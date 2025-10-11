/*
 * @lc app=leetcode id=3186 lang=cpp
 *
 * [3186] Maximum Total Damage With Spell Casting
 */

// @lc code=start
class Solution {
public:
    int lb(vector<int> &power, long long target){ 
        int low = 0, high = power.size()-1, mid;
        while(low <= high){
            mid = (low + high)/2;
            if(power[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
    long long f(int ind, vector<int> &power, vector<long long> &dp){
        if(ind >= power.size())
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        int nextInd = lb(power, power[ind]+3);
        int endInd = lb(power, power[ind]+1);
        long long select = 1LL * power[ind] * (endInd - ind) + f(nextInd, power, dp);
        long long notSelect = f(endInd, power, dp);
        return dp[ind] = max(select, notSelect);
    }
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        vector<long long> dp(power.size(), -1);
        return f(0, power, dp);
    }
};
// @lc code=end

