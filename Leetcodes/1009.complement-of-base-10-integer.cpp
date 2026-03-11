/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){return 1;}
        int ans = 0;
        int pos = 0;
        while(n){
            int bit = (n&1)^1;
            ans|=(bit<<pos);
            n>>=1;
            ++pos;
        }
        return ans;
    }
};
// @lc code=end

