/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
   public:
    void preorder(TreeNode* root, string& ans) {
        if (!root) {
            ans += "N,";
            return;
        }
        ans += to_string(root->val) + ",";
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        preorder(root, ans);
        return ans;
    }
    vector<string> split(const string& s, char delim) {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delim)) {
            tokens.push_back(token);
        }
        return tokens;
    }
    TreeNode* buildTree(vector<string>& tokens, int& idx) {
        if (idx >= tokens.size() || tokens[idx] == "N") {
            idx++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(tokens[idx]));
        idx++;
        root->left = buildTree(tokens, idx);
        root->right = buildTree(tokens, idx);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens = split(data, ',');
        int idx = 0;
        return buildTree(tokens, idx);
    }
};
