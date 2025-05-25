class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;  // Handle empty tree

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* top = st.top();
            st.pop();

            if (top->right) {
                st.push(top->right);
            }
            if (top->left) {
                st.push(top->left);
            }

            if (!st.empty()) {
                top->right = st.top();
            }

            top->left = nullptr;
        }
    }
};
