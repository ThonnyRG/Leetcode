/*
 * @lc app=leetcode id=3542 lang=cpp
 *
 * [3542] Minimum Operations to Convert All Elements to Zero
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        stack<int> stack; 
        stack.push(0);

        for (const int num : nums)
        {
        while (!stack.empty() && stack.top() > num)
        {
            stack.pop();
        }if (stack.empty() || stack.top() < num)
        {
            ++ans;
            stack.push(num);
        }
        
           
        }
        return ans;

    }
};
// @lc code=end

