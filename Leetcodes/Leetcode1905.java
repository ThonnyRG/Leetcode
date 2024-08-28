class Solution {
    private int[] islandRoot;
    private byte[] islandStatus; // 0: unvisited, 1: valid sub-island, 2: invalid sub-island
    private int numRows, numCols;

    public int countSubIslands(int[][] grid1, int[][] grid2) {
        numRows = grid2.length;
        numCols = grid2[0].length;
        int totalCells = numRows * numCols;
        islandRoot = new int[totalCells];
        islandStatus = new byte[totalCells];

        // Initialize islandRoot array and perform union for grid2
        for (int i = 0; i < totalCells; i++) {
            islandRoot[i] = i;
        }

        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                if (grid2[row][col] == 1) {
                    int currentIndex = row * numCols + col;
                    if (col + 1 < numCols && grid2[row][col + 1] == 1) {
                        unionIslands(currentIndex, currentIndex + 1);
                    }
                    if (row + 1 < numRows && grid2[row + 1][col] == 1) {
                        unionIslands(currentIndex, currentIndex + numCols);
                    }
                }
            }
        }

        // Mark invalid sub-islands
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                if (grid2[row][col] == 1 && grid1[row][col] == 0) {
                    int rootIndex = findIslandRoot(row * numCols + col);
                    islandStatus[rootIndex] = 2; // Mark as invalid sub-island
                }
            }
        }

        // Count valid sub-islands
        int subIslandCount = 0;
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                if (grid2[row][col] == 1) {
                    int rootIndex = findIslandRoot(row * numCols + col);
                    if (islandStatus[rootIndex] == 0) {
                        subIslandCount++;
                        islandStatus[rootIndex] = 1; // Mark as counted
                    }
                }
            }
        }

        return subIslandCount;
    }

    private int findIslandRoot(int x) {
        if (islandRoot[x] != x) {
            islandRoot[x] = findIslandRoot(islandRoot[x]); // Path compression
        }
        return islandRoot[x];
    }

    private void unionIslands(int x, int y) {
        int rootX = findIslandRoot(x);
        int rootY = findIslandRoot(y);
        if (rootX != rootY) {
            islandRoot[rootY] = rootX;
        }
    }
}