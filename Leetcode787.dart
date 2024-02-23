import 'dart:collection';

class Solution {
  int findCheapestPrice(int n, List<List<int>> flights, int src, int dst, int k) {
    Map<int, List<List<int>>> adj = {};
    for (List<int> flight in flights) {
      adj.putIfAbsent(flight[0], () => []).add([flight[1], flight[2]]);
    }

    List<int> dist = List.filled(n, 99999999); // Integer.MAX_VALUE en Java
    dist[src] = 0;

    Queue<List<int>> q = Queue();
    q.add([src, 0]);
    int stops = 0;

    while (q.isNotEmpty && stops <= k) {
      int sz = q.length;
      while (sz-- > 0) {
        List<int> curr = q.removeFirst();
        int node = curr[0];
        int distance = curr[1];

        if (!adj.containsKey(node)) continue;

        for (List<int> next in adj[node]!) {
          int neighbour = next[0];
          int price = next[1];
          if (price + distance >= dist[neighbour]) continue;
          dist[neighbour] = price + distance;
          q.add([neighbour, dist[neighbour]]);
        }
      }
      stops++;
    }

    return dist[dst] == 99999999 ? -1 : dist[dst];
  }
}
