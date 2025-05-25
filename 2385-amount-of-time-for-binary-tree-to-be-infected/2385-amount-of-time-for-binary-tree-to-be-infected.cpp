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
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> par;
        queue<TreeNode*> q;
        TreeNode* target = nullptr;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node->val == start) target = node;
            if (node->left) {
                par[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                par[node->right] = node;
                q.push(node->right);
            }
        }
        map<TreeNode*, bool> vis;
        q.push(target);
        vis[target] = true;
        int time = -1;
        while (!q.empty()) {
            int sz = q.size();
            time++;
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front(); q.pop();

                if (node->left && !vis[node->left]) {
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if (node->right && !vis[node->right]) {
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if (par.count(node) && !vis[par[node]]) {
                    q.push(par[node]);
                    vis[par[node]] = true;
                }
            }
        }

        return time;
    }
};
