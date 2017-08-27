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
   int kthSmallest(TreeNode* root, int k) {
    int step = 0;
    int res = -1;
    inOrderKth(root,k,step,res);
    return res;
}

private:
   void inOrderKth(TreeNode* root,int k,int &step,int &res){
    if(root== nullptr){
        return;
    }

    inOrderKth(root->left,k,step,res);
    step++;
    if(k==step){
        res = root->val;
        return;
    }
    inOrderKth(root->right,k,step,res);
}
};