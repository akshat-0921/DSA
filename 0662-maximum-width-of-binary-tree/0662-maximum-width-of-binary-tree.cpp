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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int n=q.size();
            int min=q.front().second;
            int first=0,last=0;
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front().first;
                int curr_id=q.front().second-min;
                q.pop();
                if(i==0) first=curr_id;
                if(i==n-1) last=curr_id+1;
                if(curr->left) q.push({curr->left,2*curr_id});
                if(curr->right) q.push({curr->right,2*curr_id+1});
            }
            ans=max(last-first,ans);
        }
        return ans;
    }
};