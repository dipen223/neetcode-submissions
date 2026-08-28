class Solution {
public:
    void dfs(TreeNode* root, int maxSoFar, int& count){
        if(!root) return;

        if(root->val >= maxSoFar){
            count++;
        }

        int newMax = max(maxSoFar, root->val);
        dfs(root->left, newMax, count);
        dfs(root->right, newMax, count);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root, root->val, count);  
        return count;
    }
};