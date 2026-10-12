class Solution {
    public int[][] largestLocal(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[][] res = new int[n - 2][m - 2];

        for(int i = 1; i < n - 1; ++i) {
            for(int j = 1; j < m - 1; ++j) {
                int temp = 0;

                for(int k = i - 1; k <= i + 1; ++k) {
                    for(int l = j - 1; l <= j + 1; ++l) {
                        temp = Math.max(temp, grid[k][l]);
                    }
                }

                res[i - 1][j - 1] = temp;
            }
        }

        return res;
    }
}