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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if(root==nullptr){
            return res;
        }
        st.push(root);
        TreeNode* last = new TreeNode(-1);
        TreeNode *node = root;
        bool is_leaf = false, is_finished = false;
        while(!st.empty()){
            node = st.top();
            is_leaf = node->left==nullptr&&node->right==nullptr;
            is_finished = is_leaf||(node->right==nullptr&&last==node->left)||last==node->right;
            if(is_finished){
                last = node;
                st.pop();
                res.push_back(node->val);
            }else{
                ///进栈顺序为先右再左
                if(node->right!=nullptr){
                    st.push(node->right);
                }
                if(node->left!=nullptr){
                    st.push(node->left);
                }
               
            }
        }
        return res;
        
    }
};