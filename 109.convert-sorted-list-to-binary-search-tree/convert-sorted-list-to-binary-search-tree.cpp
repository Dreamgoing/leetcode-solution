class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
      return _sortedListToBst(head, nullptr);
    }
    TreeNode* _sortedListToBst(ListNode* head, ListNode* last){
      if(head==last){
        return nullptr;
      }
      ListNode* fast = head, *slow = head;
      while(fast!=last&&fast->next!=last){
        slow = slow->next;
        fast = fast->next->next;
      }
      TreeNode* node = new TreeNode(slow->val);
      node->left = _sortedListToBst(head, slow);
      node->right = _sortedListToBst(slow->next, last);
      return node;
    }
};