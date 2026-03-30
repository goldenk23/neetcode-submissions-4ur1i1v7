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
    unordered_map<TreeNode*, TreeNode*>parent;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        parent[root]=nullptr;
        dfs(root);
        vector<TreeNode*>vecp;
        vector<TreeNode*>vecq;
        while(p){
            vecp.push_back(p);
            p=parent[p];
        }
        while(q){
            vecq.push_back(q);
            q=parent[q];
        }
        reverse(vecp.begin(),vecp.end());
        reverse(vecq.begin(),vecq.end());
        int lca=-1;
        int k=0;
       while(vecp[k]==vecq[k]){
        k++;
       }
        k--;
        return vecp[k];
    }
    void dfs(TreeNode* node){
        if(node==nullptr){return;}
        TreeNode* left=node->left;
        TreeNode* right=node->right;
        if(left){
            parent[left]=node;
            dfs(node->left);
        }
        if(right){
            parent[right]=node;
            dfs(right);
        }
    }
};
