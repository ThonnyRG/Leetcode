/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution {
public:
    void dfs(int x, int y, vector<vector<bool>> &visited, vector<vector<int>>& heights) {
        visited[x][y] = true;

        for(int i=0; i<4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(newX >= 0 && newY >= 0 && newX < m && newY < n && !visited[newX][newY] && (heights[newX][newY] >= heights[x][y])) {
                dfs(newX, newY, visited, heights);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacVisit(m ,vector<bool>(n, false));
        vector<vector<bool>> atlVisit(m ,vector<bool>(n, false));

        for(int i=0; i<m; i++) {
            dfs(i, 0, pacVisit, heights);
            dfs(i, n-1, atlVisit, heights);
        }

        for(int i=0; i<n; i++) {
            dfs(0, i, pacVisit, heights);
            dfs(m-1, i, atlVisit, heights);
        }

        vector<vector<int>> ans;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(pacVisit[i][j] && atlVisit[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }

private:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int m;
    int n;
};
// @lc code=end

