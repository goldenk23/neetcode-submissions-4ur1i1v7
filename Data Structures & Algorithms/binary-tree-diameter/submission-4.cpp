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
    int diameter = 0;
    int solve(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int left_height = solve(node->left);  // height of left subtree
        int right_height = solve(node->right);
        diameter = max(diameter, left_height + right_height);
        return 1 + max(left_height, right_height);
    }

   public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        solve(root);
        return diameter;
    }
};
