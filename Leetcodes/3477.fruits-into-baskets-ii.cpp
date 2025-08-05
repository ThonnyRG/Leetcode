/*
 * @lc app=leetcode id=3477 lang=cpp
 *
 * [3477] Fruits Into Baskets II
 */

// @lc code=start
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int unreplacedFruits = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(fruits[i] <= baskets[j]){
                    unreplacedFruits--;
                    baskets[j] = 0;
                    break;
                }
            }
            
        }
        return unreplacedFruits;
    }
};
// @lc code=end

