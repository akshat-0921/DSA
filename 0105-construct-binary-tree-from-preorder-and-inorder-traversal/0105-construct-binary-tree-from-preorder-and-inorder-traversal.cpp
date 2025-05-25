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
    TreeNode* f(int psi, int pei, int isi, int iei, vector<int> &preorder, vector<int> &inorder){
        if((psi > pei) || (isi > iei))return NULL;
        TreeNode* root = new TreeNode(preorder[psi]);

        int k = isi;
        while(inorder[k] != preorder[psi])k++;

        int ct = k-isi;
        root->left = f(psi+1, psi+ct, isi, k-1, preorder, inorder);
        root->right = f(psi+ct+1, pei, k+1, iei, preorder, inorder);

        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int psi = 0, pei = preorder.size()-1;
        int isi = 0, iei = inorder.size()-1;

        return f(psi, pei, isi, iei, preorder, inorder);
    }
};