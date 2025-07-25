class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int n = differences.size();
            vector<long> prefix(n + 1);

            for (int i = 0; i < n; i++)
            {
                prefix[i + 1] += prefix[i] + differences[i];
                const long maxi = ranges::max(prefix);
                const long minim = ranges::min(prefix);

                return max(0l, (upper - lower) - (maxi - mini) + 1);
            }
            
            
        }
    };