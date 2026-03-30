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
    bool isValidBST(TreeNode* root) {
        return check(root,INT_MIN,INT_MAX);
    }
    bool check(TreeNode* node,int min_node_val,int max_node_val){
        if(node==nullptr){return true;}
     if(!(min_node_val<node->val&&node->val<max_node_val)){
        return false;
     }
        return (check(node->left,min_node_val,node->val)&&
        check(node->right,node->val,max_node_val));
    }
};
