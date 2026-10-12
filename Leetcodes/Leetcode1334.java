class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        long[][] matrix = new long[n][n];
        
        // Initialize the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    matrix[i][j] = 0L; // Distance from a city to itself is zero
                } else {
                    matrix[i][j] = Long.MAX_VALUE / 2; // Large value representing no direct connection
                }
            }
        }

        // Populate the matrix with edge values
        for (int[] edge : edges) {
            int a = edge[0];
            int b = edge[1];
            int cost = edge[2];
            matrix[a][b] = cost;
            matrix[b][a] = cost;
        }

        // Apply Floyd-Warshall algorithm to compute shortest paths
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    long newCost = matrix[i][k] + matrix[k][j];
                    if (newCost < matrix[i][j]) {
                        matrix[i][j] = newCost;
                    }
                }
            }
        }

        // Determine the city with the fewest neighbors within the threshold
        int station = -1;
        int minNeighbors = Integer.MAX_VALUE;
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            if (count <= minNeighbors) { // If tied, return the city with the higher index
                minNeighbors = count;
                station = i;
            }
        }

        return station;
    }
}
