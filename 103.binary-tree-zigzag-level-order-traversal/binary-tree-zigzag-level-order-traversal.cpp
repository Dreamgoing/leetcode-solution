class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> dq;
        vector<vector<int> >res;
        res.clear();
        if(root==nullptr){
          return res;
        }
        bool is_even = true;
        dq.push_back(root);
        TreeNode* it = nullptr;
        while (!dq.empty()) {
          vector<int> level;
          level.clear();
          int size = dq.size();
            for(int i = 0;i<size;i++){
              if(is_even){
                it = dq.front();
                dq.pop_front();
                level.push_back(it->val);
                if(it->left!=nullptr){
                  dq.push_back(it->left);
                }
                if(it->right!=nullptr){
                  dq.push_back(it->right);
                }
              }else{
                it = dq.back();
                dq.pop_back();
                level.push_back(it->val);
                if(it->right!=nullptr){
                  dq.push_front(it->right);
                }
                if(it->left!=nullptr){
                  dq.push_front(it->left);
                }
              }
            }
            is_even = !is_even;
            res.push_back(level);
        }
        return res;
    }
};
