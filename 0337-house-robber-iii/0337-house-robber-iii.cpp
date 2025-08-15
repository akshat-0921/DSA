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
    int ans(TreeNode* root,int par,map<pair<TreeNode*,int>, int> &mpp)
    {
        if(root==NULL) return 0;
        if(mpp.find({root,par})!=mpp.end()) return mpp[{root,par}];
        if(par==1) return mpp[{root,par}]=ans(root->left,0,mpp)+ans(root->right,0,mpp);
        int take=root->val+ans(root->left,1,mpp)+ans(root->right,1,mpp);
        int ntake=ans(root->left,par,mpp)+ans(root->right,par,mpp);
        return mpp[{root,par}]=max(take,ntake);
    }
public:
    int rob(TreeNode* root) {
        map<pair<TreeNode*,int>, int> mpp;
        int val= ans(root,0,mpp);
        return val;
    }
};