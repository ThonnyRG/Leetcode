class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                v.push_back({nums[i][j], i});
            }
        }
        sort(v.begin(), v.end());

        int n = nums.size();

        vector<int> ans;
        unordered_map<int, int> mp;
        int lefty = 0;
        int righty = 1e9;
        int l = 0;
        for (int r = 0; r < v.size(); r++) {

            mp[v[r].second]++;
            while (mp.size() == n) {
                if ((v[r].first - v[l].first) < (righty - lefty)) {
                    righty = v[r].first;
                    lefty = v[l].first;
                }
                mp[v[l].second]--;
                if (mp[v[l].second] == 0)
                    mp.erase(v[l].second);
                l++;
            }
        }
        ans = {lefty, righty};
        return ans;
    }
};