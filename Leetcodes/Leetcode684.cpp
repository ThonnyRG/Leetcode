class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find (int u){
        if (parent[u]==u) return u;
        return parent[u]=find(parent[u]);
    }

    void unionfind(int x, int y){
        x = find(x);
        y = find(y);
        if (rank[x]>=rank[y]){
            parent[y] = x;
            rank[x] += rank[y];
        }else{
            parent[x] = y;
            rank[y] += rank[x];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {


        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1);
        for (int i = 0;i<=n;i++){
            parent[i] = i;
            rank[i] = 1;
        }

        for (auto it : edges){
            int x = it[0]; int y = it[1];
            int parent_x = find(x);
            int parent_y = find(y);
            if (parent_x==parent_y){
                return it;
            }
            else{
                unionfind(parent_x,parent_y);
            }
        }
        return vector<int>();
    }
};