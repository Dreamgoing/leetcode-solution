class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return getSubRoot(nums,0,nums.size());
    }
    TreeNode* getSubRoot(vector<int> &nums, int l, int r){
      if(l>=r){
        return nullptr;
      }
      int m = l+(r-l)/2;
      TreeNode* node = new TreeNode(nums[m]);
      node->left = getSubRoot(nums,l,m);
      node->right = getSubRoot(nums,m+1,r);
      return node;
    }
};
