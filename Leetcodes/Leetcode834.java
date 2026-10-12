import java.util.*;

class Solution {
    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        var answer = new int[n];
        var graph = new HashMap<Integer, List<Integer>>();
        for (var i = 0; i < n; i++) graph.put(i, new LinkedList<>());
        for (var edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        var root = ThreadLocalRandom.current().nextInt(0, n); // any vertex can be a root
        var subtreeSize = new int[n];
        var distance = new int[n];
        var visited = new boolean[n];
        computeRootStatistics(root, graph, 0, visited, subtreeSize, distance);
        answer[root] = Arrays.stream(distance).sum();
        computeAllDistanceSums(root, n, graph, answer, subtreeSize);
        return answer;
    }

    private void computeAllDistanceSums(int root, int n, HashMap<Integer, List<Integer>> graph, int[] answer, int[] subtreeSize) {
        for (Integer child : graph.get(root)) {
            if (answer[child] == 0) {
                answer[child] = (answer[root] - subtreeSize[child]) + (n - subtreeSize[child]);
                computeAllDistanceSums(child, n, graph, answer, subtreeSize);
            }
        }
    }

    private void computeRootStatistics(int root, HashMap<Integer, List<Integer>> graph, int level, boolean[] visited, int[] subtreeSize, int[] distance) {
        visited[root] = true;
        var size = 1;
        for (Integer child : graph.get(root)) {
            if (!visited[child]) {
                computeRootStatistics(child, graph, level + 1, visited, subtreeSize, distance);
                size += subtreeSize[child];
            }
        }
        distance[root] = level;
        subtreeSize[root] = size;
    }
}
