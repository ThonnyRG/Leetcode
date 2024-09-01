class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        int size = original.length;  // Get the size of the original 1D array

        // If the total number of elements doesn't match m * n, return an empty 2D array
        if (size != m * n) {
            return new int[0][0];
        }

        int[][] Two_D = new int[m][n];  // Initialize the 2D array

        // Loop through the number of rows
        for (int i = 0; i < m; ++i) {
            // Loop through the number of columns
            for (int j = 0; j < n; ++j) {
                // Set the appropriate element in the 2D array
                Two_D[i][j] = original[i * n + j];
            }
        }

        return Two_D;  // Return the constructed 2D array
    }
}