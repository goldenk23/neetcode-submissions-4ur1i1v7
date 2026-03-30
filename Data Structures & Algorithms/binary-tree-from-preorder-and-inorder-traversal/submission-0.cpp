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
    unordered_map<int,int>mp2;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp2[inorder[i]]=i;
        }
        return generate_tree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* generate_tree( vector<int>& preorder, vector<int>& inorder,
    int start_pre, int end_pre, int start_in,int end_in){
        if(start_pre>end_pre||start_in>end_in){return nullptr;}
        TreeNode* root=new TreeNode(preorder[start_pre]);
         int root_indx=mp2[root->val];
         int left_length=root_indx-start_in;
        root->left=generate_tree(preorder,inorder,start_pre+1,start_pre+left_length,start_in,
        root_indx-1);
        root->right=generate_tree(preorder,inorder,start_pre+left_length+1,end_pre,root_indx+1,end_in);
        return root; 
    }
};
