/*
 * @lc app=leetcode id=1390 lang=cpp
 *
 * [1390] Four Divisors
 */

// @lc code=start
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        
        int total=0;
        for(int i=0;i<nums.size();i++){
            int count=0;
            int sum=0;
            for(int j=1;j<=nums[i];j++){
                if(nums[i]%j==0){
                    count++;
                    if(count > 4){
                        break;
                    }
                    sum+=j;
                }
            }
            if(count==4){
                total+=sum;
            }
        }

        return total;
    }
};
// @lc code=end

