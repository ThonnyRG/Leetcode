/*
 * @lc app=leetcode id=2169 lang=cpp
 *
 * [2169] Count Operations to Obtain Zero
 */

// @lc code=start
class Solution {
public:
    int countOperations(int num1, int num2) {
        int operations = 0;
        while (num1 != 0 && num2 != 0)
        {
         
                if (num1 >= num2)
                {
                    num1 -= num2;
                }else{
                    num2 -= num1;
                }
                operations++;
        }
          return operations;
    }
};
// @lc code=end

