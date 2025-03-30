class Solution {
    public:
        vector<int> partitionLabels(string s) {
            unordered_map<char, int> mp;
    
            // Store the last occurrence of each character
            for (int i = 0; i < s.length(); i++) {
                mp[s[i]] = i;
            }
    
            vector<int> res;
            int end = mp[s[0]], start = 0;
    
            for (int i = 1; i <= s.length(); i++) {
                if(i <= end) {
                    if(mp[s[i]] > end) {
                        end = mp[s[i]];
                    }
                } else {
                    res.push_back(end - start + 1);
                    start = i;
                    end = mp[s[i]];
                }
            }
    
            return res;
        }
    };