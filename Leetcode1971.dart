class Solution{
  bool validPath(int n, List<List<int>> edges, int source, int destination) {
    var graph = Map<int, List<int>>();
    for (int v = 0; v < n; v++) {
      graph[v] = [];
    }
    for (var edge in edges) {
      graph[edge[0]]!.add(edge[1]);
      graph[edge[1]]!.add(edge[0]);
    }

    var bfsQ = Queue<int>();
    var visited = Set<int>();
    bfsQ.add(source);
    while (bfsQ.isNotEmpty) {
      var v = bfsQ.removeFirst();
      if (visited.contains(v)) continue;
      if (v == destination) return true;
      graph[v]!.forEach((adj) => bfsQ.add(adj));
      visited.add(v);
    }
    return false;
  }
}