class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long maxProduct = 0;
            int maxElement = 0;
            int maxDifference = 0;

            for(int num : nums){
                maxProduct = max(maxProduct, static_cast<long long>(maxDifference) * num);
                maxElement = max(maxElement, num);
                maxDifference = max(maxDifference, maxElement - num);
            }
            return maxProduct;
        }
    };