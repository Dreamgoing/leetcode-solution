//
// Created by WangRuoxuan on 2017/8/22.
//


class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
      int sum = get_allsum(root);
      if(sum%2==0&&(root->right!=nullptr||root->left!=nullptr)){
        bool found = false;
        _dfs(sum, root, found);
        return found;
      }else{
        return false;
      }
    }
    int _dfs(int sum, TreeNode* root, bool &found){
      if(root==nullptr||found){
        return 0;
      }
      int subsum = _dfs(sum, root->left, found) + _dfs(sum ,root->right, found) + root->val;
      if(subsum==sum/2){
        found = true;
      }
      return subsum;
    }
    int get_allsum(TreeNode* root){
      if(root==nullptr){
        return 0;
      }
      return get_allsum(root->left) + get_allsum(root->right) + root->val;
    }
};