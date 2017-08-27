class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int pos = 0;
      return _buildTree(preorder,pos,inorder,0,inorder.size()-1);
    }

    TreeNode* _buildTree(vector<int>& preorder, int &pos, vector<int>& inorder,int l,int r){
      if(pos==preorder.size()){
        return nullptr;
      }
      int node_idx = getidx(preorder[pos], inorder,l,r);
      if(node_idx==-1){
        return nullptr;
      }
      TreeNode* node = new TreeNode(preorder[pos]);
      pos++;
      node->left = _buildTree(preorder,pos,inorder,l,node_idx-1);
      node->right = _buildTree(preorder,pos,inorder,node_idx+1,r);
      return node;
    }
    int getidx(int key, vector<int>& inorder, int l,int r){
      for(int i = l;i<=r;i++){
        if(key==inorder[i]){
          return i;
        }
      }
      return -1;
    }
};
