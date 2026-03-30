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
    int good_node=0;
public:
    int goodNodes(TreeNode* root) {
        dfs(root,-200);
        return good_node;
    }
    void dfs(TreeNode* node, int max_node_val){
        if(node==nullptr){return ;}
        if(node->val>=max_node_val){
            good_node++;
            max_node_val=node->val;
        }
        dfs(node->left,max_node_val);
        dfs(node->right,max_node_val);
    }
};
