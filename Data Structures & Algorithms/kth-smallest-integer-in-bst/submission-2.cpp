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
    int ans;
    void search(TreeNode* node,int& count,int target ){
        if(node==nullptr || count==target){
            return;
        }
        search(node->left,count,target);
        count++;
        if(count==target){
            ans=node->val;
        }
        search(node->right,count,target);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        search(root,count,k);
        return ans;
    }
};
