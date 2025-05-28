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
    int ans=0;
private:
    void check(TreeNode* node,int tar)
    {
        if(node==NULL) return;
        check(node->left,tar);
        check1(node,tar-node->val);
        check(node->right,tar);
    }
    void check1(TreeNode* node,int tar)
    {
        if(node==NULL) return;
        if(tar==node->val) {ans=1;return;}
        if(tar>node->val) check(node->right,tar);
        check(node->left,tar);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        check(root,k);
        return ans;
    }
};