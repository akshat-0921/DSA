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
    int res=0;
private:
    void ans(TreeNode* root,int k,int& cnt)
    {
        if(root==NULL) return;
        ans(root->left,k,cnt);
        if(++cnt==k) 
        {
            res=root->val;
            return;
        }
        ans(root->right,k,cnt);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        ans(root,k,cnt);
        return res;
    }
};