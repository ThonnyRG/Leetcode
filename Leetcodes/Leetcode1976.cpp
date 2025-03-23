class Solution {
    typedef pair<long, long> ipair;
public:
    int countPaths(int n, vector<vector<int>>& E) {
        vector<vector<pair<int, int>>> G(n);
        for (auto &e : E) {
            int u = e[0], v = e[1], t = e[2];
            G[u].emplace_back(v, t);
            G[v].emplace_back(u, t);
        }
        long mod = 1e9 + 7;
        vector<long> dist(n, LONG_MAX), cnt(n);
        priority_queue<ipair, vector<ipair>, greater<>> pq; // time, city
        dist[0] = 0;
        cnt[0] = 1;
        pq.emplace(0, 0);
        while (pq.size()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (cost > dist[u]) continue;
            for (auto &[v, time] : G[u]) {
                long c = cost + time;
                if (c < dist[v]) {
                    dist[v] = c;
                    cnt[v] = cnt[u];
                    pq.emplace(c, v);
                } else if (c == dist[v]) cnt[v] = (cnt[v] + cnt[u]) % mod;
            }
        }
        return cnt[n - 1];
    }
};
