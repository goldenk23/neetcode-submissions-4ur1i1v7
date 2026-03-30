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
    unordered_map<TreeNode*,pair<int,int>>child_count;
public:
    int kthSmallest(TreeNode* root, int k) {
        traverse(root);
        return find_kth_smallest(root,k,child_count[root].first+1);
    }
    int  traverse(TreeNode* node){
        if(node==nullptr){return 0;}
        child_count[node].first=traverse(node->left);
        child_count[node].second=traverse(node->right);
        return 1+child_count[node].first+child_count[node].second;
    }
    int find_kth_smallest(TreeNode* node,int k,int curr_pos){
        if(curr_pos==k){return node->val;}
       if(curr_pos<k){
        int new_pos=curr_pos+1+child_count[node->right].first;
        return find_kth_smallest(node->right,k,new_pos);
       }else{
        int new_pos=curr_pos-1-child_count[node->left].second;
        return find_kth_smallest(node->left,k,new_pos);
       }
    }
};
