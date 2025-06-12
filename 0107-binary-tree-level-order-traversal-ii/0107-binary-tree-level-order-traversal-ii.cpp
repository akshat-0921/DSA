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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>v;
        if(root==nullptr) return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int>v1;
            for(int i=1;i<=sz;i++){
                TreeNode *tem=q.front();
                q.pop();
                v1.push_back(tem->val);
                if(tem->left){
                    q.push(tem->left);
                }
                if(tem->right){
                    q.push(tem->right);
                }
            }
            v.push_back(v1);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};