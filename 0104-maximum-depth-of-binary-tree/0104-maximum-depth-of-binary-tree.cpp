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
    private:
        int f(TreeNode* root)
        {
            if(root==NULL) return 0;
            return 1+max(f(root->right),f(root->left));
        }
public:
    int maxDepth(TreeNode* root) {
        return f(root);
    }
};