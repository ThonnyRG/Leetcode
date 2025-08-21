/*
 * @lc app=leetcode id=1504 lang=cpp
 *
 * [1504] Count Submatrices With All Ones
 */

// @lc code=start
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size() , i , j , k;
        int dp[n][m];
        for(i = 0 ; i < n ; i++){
            int c = 0;
            for(j = m - 1 ; j >= 0 ; j--){
                if(mat[i][j] == 1){
                    c++;
                }
                else{
                    c = 0;
                }
                dp[i][j] = c;
            }
        }
        int ans = 0;
        for(i = 0 ; i < n ; i++){
            for(j = 0 ; j < m ; j++){
                int x = INT_MAX;
                for(k = i ; k < n ; k++){
                    x = min(x , dp[k][j]);
                    ans = ans + x;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

