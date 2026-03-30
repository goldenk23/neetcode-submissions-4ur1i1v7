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
int diameter=0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;
    }
    int depth(TreeNode* root){
        if(root==nullptr){return 0;}
        int lh=depth(root->left);
        int rh=depth(root->right);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);
    }
};
