class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);

        vector<vector<int> > res;
        res.clear();
        if(root==NULL){
            return res;
        }
        while (!que.empty()){
            vector<int> level;
            level.clear();
            int size = (int) que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* now = que.front();
                que.pop();
                level.push_back(now->val);
                if(now->left!=NULL){
                    que.push(now->left);
                }
                if(now->right!=NULL){
                    que.push(now->right);
                }
            }
            res.push_back(level);

        }
        return res;
    }

};