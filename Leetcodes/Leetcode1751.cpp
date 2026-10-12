class Solution {
public:
    bool check(vector<int>& nums) {
       int orderCount = 0;

       int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[(i + 1) % n])
            {
                orderCount ++;
            }
            
        }
        return orderCount <= 1;

    }
};