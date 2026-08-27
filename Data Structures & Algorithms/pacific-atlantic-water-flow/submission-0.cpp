class Solution {
   public:
    void dfs(int row, int col, vector<vector<bool>>& vis, int prevHeight,
             vector<vector<int>>& heights) {
        if (row < 0 || col < 0 || row == heights.size() || col == heights[0].size() ||
            vis[row][col] || heights[row][col] < prevHeight) {
            return;
        }
        vis[row][col] = true;
        dfs(row - 1, col, vis, heights[row][col], heights);
        dfs(row + 1, col, vis, heights[row][col], heights);
        dfs(row, col - 1, vis, heights[row][col], heights);
        dfs(row, col + 1, vis, heights[row][col], heights);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for (int j = 0; j < cols; j++) {
            dfs(0, j, pacific, heights[0][j], heights);                 // top pacific
            dfs(rows - 1, j, atlantic, heights[rows - 1][j], heights);  // bottom atlantic
        }

        for (int i = 0; i < rows; i++) {
            dfs(i, 0, pacific, heights[i][0], heights);                // left pacific
            dfs(i, cols - 1, atlantic, heights[i][cols - 1], heights);  // right atlantic
        }

        vector<vector<int>> ans;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};
