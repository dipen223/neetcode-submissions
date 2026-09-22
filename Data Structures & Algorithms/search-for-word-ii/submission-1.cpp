class Node {
   public:
    bool endOfWord;
    unordered_map<char, Node*> children;

    Node() { endOfWord = false; }
};

class Trie {
   public:
    Node* root;

    Trie() { root = new Node(); }

    void insert(string word) {
        Node* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->children.count(word[i]) == 0) {
                temp->children[word[i]] = new Node();
            }
            temp = temp->children[word[i]];
        }
        temp->endOfWord = true;
    }
};

class Solution {
   public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(int row, int col, vector<vector<char>>& board, Node* node, string& path, vector<string>& ans) {
        char c = board[row][col];
        if (c == '#' || node->children.count(c) == 0) return;

        Node* next = node->children[c];
        path.push_back(c);
        if (next->endOfWord) {
            ans.push_back(path);
            next->endOfWord = false;
        }
        board[row][col] = '#';
        for (int k = 0; k < 4; k++) {
            int nextRow = row + dr[k];
            int nextCol = col + dc[k];
            if (nextRow >= 0 && nextCol >= 0 && nextRow < board.size() &&
                nextCol < board[0].size()) {
                dfs(nextRow, nextCol, board, next, path, ans);
            }
        }
        board[row][col] = c;
        path.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (string word : words) {
            trie.insert(word);
        }
        vector<string> ans;
        string path = "";

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(i, j, board, trie.root, path, ans);
            }
        }

        return ans;
    }
};