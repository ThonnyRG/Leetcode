class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            vector<int> ans;
            unotdered_map<int, int> ballToColor, colorCount;

            for (const vector<int>& query: queries) {
                const int ball = query[0];
                const int color = query[1];
                if (const auto it = ballTOcolor.fin(ball); it != ballToColor.cend()) {
                    const int prevColor = it -> second;
                    if(--colorCount[prevColor] == 0)
                    colorCount.erase(prevColor);
                }
                ballToColor[ball] = color;
            ++colorCount[color];
            ans.push_back(colorCount.size());
            }
            return ans;
        }
    };