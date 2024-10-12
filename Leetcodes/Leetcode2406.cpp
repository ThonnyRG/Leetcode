class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int n = (int)intervals.size();
        sort(begin(intervals), end(intervals));
        int ans = 0;
        multiset<pair<int, int>> st;
        for (auto it : intervals)
        {
            st.insert(make_pair(it[0], it[1])); 
        }
        while (!st.empty()) {
            auto it = *st.begin();
            st.erase(st.begin());
            int cur = it.second;
            while (true) {
                auto mx = st.upper_bound(make_pair(cur, INT_MAX));
                if (mx == st.end()) break;
                cur = mx->second;
                st.erase(mx);
            }
            ans++;
        }
        return ans;
    }
};
