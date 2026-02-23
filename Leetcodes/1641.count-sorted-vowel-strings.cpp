/*
 * @lc app=leetcode id=1641 lang=cpp
 *
 * [1641] Count Sorted Vowel Strings
 */

// @lc code=start
class Solution {
public:
    int countVowelStrings(int n) {
       int dp[n][5];
       memset(dp, 0, sizeof dp);

       fuction<int(int, int)> dfs = [&] (int currenLenght, int starVowel){
        if (currentLength >= n)
        {
            return 1;
        }
        if (dp[currentLength][starVowel])
        {
            return dp[currenLenght][starVowel];
        }
        int count = 0;
        for (int nextVowel = starVowel; nextVowel < 5; ++nextVowel)
        {
            count += dfs(currenLenght + 1, nextVowel);
        }
        
        return dp[currenLenght][starVowel] = count;
       };
       return dfs(0,0);
    }
};
// @lc code=end

