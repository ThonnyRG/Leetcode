class Solution {
public:
        long long gridGame(vector<vector<int>>& grid) {
            long long i, j, x, n = grid[0].size();
            if(n == 1) return 0;
            long long min_sum = LLONG_MAX;

            long long pSum[2][n];

            pSum[0][0] = grid[0][0];
            for (int i = 1; i < n; i++) pSum[0][i] = grid[0][i] + pSum[0][i - 1];

            pSum[1][0] = grid[1][0];
            for (int i = 1; i < n; i++) pSum[1][i] = grid[1][i] + pSum[1][i - 1];

            min_sum = min(pSum[0][n - 1] - pSum[0][0], pSum[1][n - 2]);
            
            for (int i = 1; i < n - 1; i++)
            {
                long long cv = max(pSum[0][n-1] - pSum[0][i], pSum[1][i - 1]);
                    if (cv < min_sum) min_sum = cv;
                    
            }
            return min_sum;

        }
};