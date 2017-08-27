class Solution{
public:
    bool hasCycle(ListNode *head){
        ListNode* one_step = head;
        ListNode* two_step = head;
        while (one_step!= nullptr && two_step!= nullptr && two_step->next!= nullptr){
            one_step = one_step->next;
            two_step = two_step->next->next;
            if(one_step==two_step){
                return true;
            }
        }
        return false;
    }
};