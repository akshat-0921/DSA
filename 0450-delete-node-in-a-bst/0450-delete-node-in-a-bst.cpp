/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode * dummy = new TreeNode(-1) ;
        dummy->left = root ; 
        TreeNode * parent = dummy ; 
        while(root){
            if (root->val == key) {
                if(root->left == nullptr && root->right == nullptr){
                    if (parent->left == root) {
                        parent->left = nullptr;
                    } else {
                        parent->right = nullptr;
                    }
                    delete root; 
                } 
                else if(root->left == nullptr){
                    if (parent->left == root) {
                        parent->left = root->right;
                    } else {
                        parent->right = root->right;
                    }
                    delete root; 
                }  
                else if(root->right == nullptr){
                    if (parent->left == root) {
                        parent->left = root->left;
                    } else {
                        parent->right = root->left;
                    }
                    delete root; 
                } 
                else{
                    if (parent->left == root) {
                        parent->left = root->right;
                    } else {
                        parent->right = root->right;
                    }
                    TreeNode* L = root->left;
                    TreeNode* R = root->right;
                    root->left = nullptr;
                    root->right = nullptr;
                    while (R->left != nullptr) {
                        R = R->left;
                    }
                    R->left = L; 
                } 
                return dummy->left;
            } else if (root->val > key) {
                parent = root;
                root = root->left;
            } else {
                parent = root;
                root = root->right;
            }
        }
        return dummy->left ; 
    }
};