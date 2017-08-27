class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head== nullptr||head->next== nullptr){
            return head;
        } else{
//            return reverseListRec(head, nullptr);
            return reverseListIter(head);
        }
    }

private:
    ListNode* reverseListRec(ListNode* head,ListNode* pre){
        if(head== nullptr){
            return nullptr;
        }
        if(head->next== nullptr){
            head->next = pre;

            ///found rhead
            return head;
        }
        ListNode* res = reverseListRec(head->next,head);
        head->next = pre;
        return res;
    }
    ListNode* reverseListIter(ListNode* head){
        ListNode* cur = head;
        ListNode* tmp = nullptr;
        ListNode* pre = nullptr;
        while (cur != nullptr){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};