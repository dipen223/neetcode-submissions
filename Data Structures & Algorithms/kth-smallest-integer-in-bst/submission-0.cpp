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

class Solution {
public:
    void inorder_traversal(TreeNode*root,vector<int>&inorder){
        if(!root) return;

        inorder_traversal(root->left,inorder);
        inorder.push_back(root->val);
        inorder_traversal(root->right,inorder);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        inorder_traversal(root,inorder);
        priority_queue<int,vector<int>>pq;
        for(int i=0; i<inorder.size(); i++){
            pq.push(inorder[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }

        return pq.top();

    }
};

