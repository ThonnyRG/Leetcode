/*
 * @lc app=leetcode id=2092 lang=cpp
 *
 * [2092] Find All People With Secret
 */

// @lc code=start
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // create <time, index> map
        map<int, vector<int>> timeToIndexes;
        int m = meetings.size();
        for (int i = 0; i < m; i++) {
            timeToIndexes[meetings[i][2]].push_back(i);
        }
        
        UF uf(n);
        // base
        uf.unionSets(0, firstPerson);
        
        // for every time we have a pool of people that talk to each other
        // if someone knows a secret prior to this meeting - all pool will too
        // if not - reset unions from this pool
        for (auto& [time, indexes] : timeToIndexes) {
            unordered_set<int> pool;
            
            for (int ind : indexes) {
                vector<int>& currentMeeting = meetings[ind];
                uf.unionSets(currentMeeting[0], currentMeeting[1]);
                pool.insert(currentMeeting[0]);
                pool.insert(currentMeeting[1]);
            }
            
            // meeting that took place now shouldn't affect future
            // meetings if people don't know the secret
            for (int i : pool) {
                if (!uf.connected(0, i)) {
                    uf.reset(i);
                }
            }
        }
        
        // if the person is connected to 0 - they know a secret
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (uf.connected(i, 0)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
    
private:
    // regular union find
    class UF {
    public:
        vector<int> parent, rank;
        
        UF(int n) : parent(n), rank(n, 0) {
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        
        void unionSets(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            
            if (rootP == rootQ)
                return;
            
            if (rank[rootP] < rank[rootQ]) {
                parent[rootP] = rootQ;
            } else {
                parent[rootQ] = rootP;
                if (rank[rootP] == rank[rootQ]) {
                    rank[rootP]++;
                }
            }
        }
        
        int find(int p) {
            while (parent[p] != p) {
                p = parent[parent[p]];
            }
            return p;
        }
        
        bool connected(int p, int q) {
            return find(p) == find(q);
        }
        
        void reset(int p) {
            parent[p] = p;
            rank[p] = 0;
        }
    };
};
// @lc code=end