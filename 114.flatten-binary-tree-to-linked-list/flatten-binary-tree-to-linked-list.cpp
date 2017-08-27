class Solution {
public:
    void flatten(TreeNode* root) {
      TreeNode* pre = new TreeNode(0);
      stack<TreeNode*> st;
      if(root==nullptr){
        return;
      }
      st.push(root);
      while (!st.empty()) {
        auto cur = st.top();
        st.pop();
        pre->right = cur;
        pre->left = nullptr;
        pre = cur;
        if(cur->right!=nullptr){
          st.push(cur->right);
        }
        if(cur->left!=nullptr){
          st.push(cur->left);
        }
      }
    }
};
