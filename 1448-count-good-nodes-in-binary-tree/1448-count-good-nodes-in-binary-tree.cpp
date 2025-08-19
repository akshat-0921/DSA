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
    int count=0;
    void f(TreeNode* root,int maxi)
    {
        if(root==NULL) return;
        maxi=max(root->val,maxi);
        if(maxi==root->val) count++;
        f(root->left,maxi);
        f(root->right,maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        f(root,-1);
        return count;
    }
};