/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        q.push(root);
        map<TreeNode*,TreeNode*> mpp;
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();   
            if(node->left) {
                mpp[node->left]=node;
                q.push(node->left);
            }
            if(node->right) {
                mpp[node->right]=node;
                q.push(node->right);
            }
        }
        map<TreeNode*, bool> check;
        queue<TreeNode*> pq;
        pq.push(target);
        check[target]=1;
        int dis=0;
        while(!pq.empty())
        {
            int n=pq.size();
            if(dis==k) break;
            for(int i=0;i<n;i++)
            {
                TreeNode* node=pq.front();
                pq.pop();
                if(node->left&&check[node->left]==0) {
                    pq.push(node->left);
                    check[node->left]=1;
                }
                if(node->right&&check[node->right]==0) {
                    pq.push(node->right);
                    check[node->right]=1;
                }
                if(mpp[node]&&check[mpp[node]]==0){
                    pq.push(mpp[node]);
                    check[node->left]=1;
                }
            }
            dis++;
        }
        vector<int> res;
        while(!pq.empty())
        {
            res.push_back(pq.front()->val);
            pq.pop();
        }
        return res;
    }
};