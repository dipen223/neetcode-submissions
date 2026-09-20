class WordDictionary {
    struct Node {
        unordered_map<char, Node*> children;
        bool endOfWord = false;
    };
    Node* root;

    bool dfs(Node* node, const string& word, int i) {
        if (i == word.size()) return node->endOfWord;   // base case

        char c = word[i];
        if (c == '.') {
            for (auto& [ch, child] : node->children) {
                if (dfs(child, word, i + 1)) return true;  // any path works
            }
            return false;
        }

        auto it = node->children.find(c);
        if (it == node->children.end()) return false;
        return dfs(it->second, word, i + 1);
    }

public:
    WordDictionary() { root = new Node(); }

    void addWord(string word) {
        Node* temp = root;
        for (char c : word) {
            if (!temp->children.count(c)) temp->children[c] = new Node();
            temp = temp->children[c];
        }
        temp->endOfWord = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};