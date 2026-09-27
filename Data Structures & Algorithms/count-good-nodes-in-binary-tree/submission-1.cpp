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
    int good_node = 0;
    void dfs(TreeNode* node, int max_node) {
        if (node == nullptr) {
            return;
        }
        if (node->val >= max_node) {
            good_node++;
            max_node = node->val;
        }
        dfs(node->left, max_node);
        dfs(node->right, max_node);
    }

   public:
    int goodNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        dfs(root, INT_MIN);
        return good_node;
    }
};
