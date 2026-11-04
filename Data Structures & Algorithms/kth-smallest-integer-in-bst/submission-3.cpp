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
    int count = 0;
    int ans;
    void solve(TreeNode* node, int k) {
        if (node == nullptr) {
            return;
        }
        solve(node->left, k);
        count++;
        if (count == k) {
            ans = node->val;
            return;
        }
        solve(node->right, k);
    }
   public:
    int kthSmallest(TreeNode* root, int k) {
        solve(root, k);
        return ans;
    }
};
