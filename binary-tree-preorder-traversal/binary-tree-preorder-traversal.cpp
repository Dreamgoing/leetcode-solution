

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {

        vector<int> res;
        if(root==NULL){
            return res;
        }
        stack<TreeNode *> st;
        TreeNode *node = root;
        st.push(root);
        while (!st.empty()) {
            node = st.top();
            st.pop();
            res.push_back(node->val);
            if(node->right!=NULL){
                st.push(node->right);
            }
            if(node->left!=NULL){
                st.push(node->left);
            }

        }
        return res;
    }

};