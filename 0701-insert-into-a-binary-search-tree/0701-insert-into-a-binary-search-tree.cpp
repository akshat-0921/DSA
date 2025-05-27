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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=new TreeNode(val);
        if(root==NULL) return node;
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->val==val) break;
            if(curr->val>val)
            {
                if(curr->left==NULL) curr->left=node;
                curr=curr->left;
            }
            else 
            {
                if(curr->right==NULL) curr->right=node;
                curr=curr->right;
            }
        }
        return root;
    }
};