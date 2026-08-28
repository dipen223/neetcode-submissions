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
     bool rootToNodePath(TreeNode* root, TreeNode* dest,vector<TreeNode*>&path){
        if(!root) return false;

         path.push_back(root);

        if(root->val == dest->val){
            return true;
        }

        
       bool isLeft  = rootToNodePath(root->left,dest,path);
       bool isRight =  rootToNodePath(root->right,dest,path);

       if(isLeft || isRight){
        return true;
       }

       path.pop_back();
       return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;
        rootToNodePath(root,p,path1);
        rootToNodePath(root,q,path2);

        
       TreeNode* lca = nullptr;

       for(int i=0,j=0; i<path1.size() && j < path2.size(); i++,j++){
          if(path1[i] != path2[j]){
            return lca;
          }

          lca = path1[i];

       }

       return lca;


    }
};
