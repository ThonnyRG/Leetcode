List<int> findMinHeightTrees(int n, List<List<int>> edges) {
  if (n == 1) return [0];

  List<Set<int>> adj = List.generate(n, (_) => {});
  for (var edge in edges) {
    adj[edge[0]].add(edge[1]);
    adj[edge[1]].add(edge[0]);
  }

  List<int> leaves = [];
  for (int i = 0; i < n; ++i) {
    if (adj[i].length == 1) leaves.add(i);
  }

  while (n > 2) {
    n -= leaves.length;
    List<int> newLeaves = [];
    for (int i in leaves) {
      int j = adj[i].first;
      adj[j].remove(i);
      if (adj[j].length == 1) newLeaves.add(j);
    }
    leaves = newLeaves;
  }
  return leaves;
}
