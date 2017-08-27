class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ///当前根节点为空,则返回nullptr
        if(root== nullptr){
            return nullptr;
        }

        ///当前根节点等于p或q节点中的某一个,则返回
        if(root==p||root==q){
            return root;
        }

        ///在左子树中继续查找
        TreeNode* left = lowestCommonAncestor(root->left,p,q);

        ///在右子树中继续查找
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left!= nullptr&&right!= nullptr){
            return root;
        }else if(left!= nullptr){
            return left;
        } else if(right!= nullptr){
            return right;
        } else{
            return nullptr;
        }
    }
};