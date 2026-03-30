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
    int ans=INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        find_path(root);
        return ans;
    }
    int find_path(TreeNode* node){
        if(node==nullptr){return 0;}
        int left_sum=max(0,find_path(node->left));
        int right_sum=max(0,find_path(node->right));
        ans=max(ans,node->val+left_sum+right_sum);
        return node->val+max(left_sum,right_sum);
    }
};
