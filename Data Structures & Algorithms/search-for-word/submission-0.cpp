class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int charIndex,
              vector<vector<bool>>& vis) {
        if (charIndex == word.size()) {
            return true; // matched the whole word
        }
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() ||
            vis[r][c] || board[r][c] != word[charIndex]) {
            return false;
        }

        vis[r][c] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        bool found = false;
        for (int k = 0; k < 4 && !found; k++) {
            found = dfs(board, word, r + dr[k], c + dc[k], charIndex + 1, vis);
        }

        vis[r][c] = false; // backtrack
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};