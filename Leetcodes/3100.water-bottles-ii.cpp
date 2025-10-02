/*
 * @lc app=leetcode id=3100 lang=cpp
 *
 * [3100] Water Bottles II
 */

// @lc code=start
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int count = 0;
        int current = numBottles;
        int empty = 0;

        while (true)
        {
            count += current;
            empty += current;
            current = 0;
            if (empty >= numExchange)
            {
                current += 1;
                empty -= numExchange;
                numExchange += 1;
            }else{
                break;
            }
            
        }
        return count;
       
    }
};
// @lc code=end

