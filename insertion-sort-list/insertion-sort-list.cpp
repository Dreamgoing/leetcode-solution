

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
      if(head==nullptr){
        return nullptr;
      }
      ListNode* fake = new ListNode(-1);
      fake->next = head;
      ListNode* prenow = fake;
      ListNode* now = head;
      while(now->next!=nullptr){
        ListNode* it = now->next;
        ListNode* preit = now;
        while (it!=nullptr) {
          ListNode* itnext = it->next;
          if (it->val<now->val) {
            swapListNode(prenow,now,preit,it);
          }else{
            preit = preit->next;
          }
          now = prenow->next;
          it = itnext;
        }
        prenow = prenow->next;
        now = prenow->next;
      }
      return fake->next;
    }
    void swapListNode(ListNode* prea,ListNode* a,ListNode* preb,ListNode* b){
      prea->next = b;
      auto nxtb = b->next;
      b->next = a;
      preb->next = nxtb;
    }
};
