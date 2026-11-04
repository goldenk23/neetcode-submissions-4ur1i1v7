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
    TreeNode* solve(TreeNode* node,int left_val,int right_val){
        if(node==nullptr){
            return nullptr;
        }
        if(left_val<node->val && right_val<node->val){
           return solve(node->left,left_val,right_val);
        }else if(left_val>node->val && right_val>node->val){
            return solve(node->right,left_val,right_val);
        }else{
            return node;
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int left_val=min(p->val,q->val);
        int right_val=max(p->val,q->val);
        return solve(root,left_val,right_val);
    }
};
