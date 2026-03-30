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
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)>1){return false;}
    return isBalanced(root->left)&&isBalanced(root->right);
    }
    int height(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        int lh=height(node->left);
        int rh=height(node->right);
        return 1+max(lh,rh);
    }
};
