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
    vector<int>rsv;
public:
    vector<int> rightSideView(TreeNode* root) {
       dfs(root,0);
       return rsv; 
    }
    void dfs(TreeNode* node,int level){
        if(node==nullptr){return ;}
        if(rsv.size()==level){
            rsv.push_back(node->val);
        }
        dfs(node->right,level+1);
        dfs(node->left,level+1);  
    }
};
