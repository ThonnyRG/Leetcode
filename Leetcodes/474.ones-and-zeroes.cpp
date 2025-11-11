/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution {
public:
    int f(vector<string> &strs, int m , int n , int i , int zero , int one , vector<vector<vector<int>>> &dp , unordered_map<int,pair<int,int>>& mp) {
        if(i==strs.size()) return 0;
        if(dp[i][one][zero] != -1) return dp[i][one][zero];
        int lz=mp[i].first;
        int lo = mp[i].second;
        int op1 = 0;
        if (zero + lz <= m && one + lo <= n)
            op1 = 1 + f(strs, m, n, i + 1, zero + lz, one + lo,dp,mp);
        int op2 = f(strs,m,n,i+1,zero,one,dp,mp);
        return dp[i][one][zero]=max(op1,op2);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int zero = 0; int one = 0;
        unordered_map<int,pair<int,int>> mp;
        for(int i = 0 ; i < strs.size() ; ++i) {
            int lz = 0;int lo = 0;
            for(int j = 0 ; j < strs[i].size() ; ++j) {
                if(strs[i][j] == '0') lz++;
                else lo++;
            }
            mp[i] = {lz,lo};
        }
        vector<vector<vector<int>>> dp(strs.size()+1 , vector<vector<int>> (n+1 , vector<int> (m+1,-1)));
        return max(0,f(strs,m,n,0,zero,one,dp,mp));
    }
};
// @lc code=end

