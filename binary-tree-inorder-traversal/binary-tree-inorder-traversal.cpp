class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {

        vector<int> res;
        if(root==NULL){
            return res;
        }
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *node = root;
        while (!st.empty()){
            if(node!= nullptr&&node->left!= nullptr){
                st.push(node->left);
                node=node->left;
            } else{
                node = st.top();
                st.pop();
                res.push_back(node->val);
                if(node->right!= nullptr){
                    st.push(node->right);
                    node = node->right;
                } else{
                    node= nullptr;
                }

            }
        }
        return res;
    }

};