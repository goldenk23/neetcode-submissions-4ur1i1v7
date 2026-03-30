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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root&&!subRoot){true;}
        if(!root&&subRoot||root&&!subRoot){
            return false;
        }
        if(root->val==subRoot->val){
            if(is_matched(root,subRoot)){
                return true;
            }
        }
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
    bool is_matched(TreeNode* node1, TreeNode* node2){
        if(!node1&&!node2){return true;}
        if((!node1&&node2)||(node1&&!node2)){return false;}
        if(node1->val!=node2->val){
            return false;
        }
        return is_matched(node1->left,node2->left)&&is_matched(node1->right,node2->right);
    }
};
