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
    map<int,int> inmap;
private:
    TreeNode* build(int pst,int pend,int inst,int inend,vector<int>& inorder,vector<int>& postorder)
    {
        if(pst>pend||inst>inend) return NULL;
        TreeNode* root=new TreeNode(postorder[pend]);
        int par=inmap[root->val];
        int left=par-inst;
        root->left=build(pst,pst+left-1,inst,par-1,inorder,postorder);
        root->right=build(pst+left,pend-1,par+1,inend,inorder,postorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
        {
            inmap[inorder[i]]=i;
        }
        TreeNode* root = build(0,postorder.size()-1,0,inorder.size()-1,inorder,postorder);
        return root;
    }
};