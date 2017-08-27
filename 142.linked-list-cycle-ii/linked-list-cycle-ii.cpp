class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* one_step = head;
        ListNode* two_step = head;
        bool found = false;
        int all_step = 0;
        while (one_step!= nullptr && two_step!= nullptr && two_step->next!= nullptr){
            one_step = one_step->next;
            all_step++;
            two_step = two_step->next->next;
            if(one_step==two_step){
                found = true;
                break;
            }
        }
        if(!found){
            return nullptr;
        } else{
            int cycle_step = 1;
            ListNode* cycle_iter = one_step->next;
            while (cycle_iter!= one_step){
                cycle_iter = cycle_iter->next;
                cycle_step++;
            }
            ListNode* pre_node = head;
            ListNode* res_node = head;
            int dis = 0;
            while (true){
                pre_node = pre_node->next;
                if(dis<cycle_step){
                    dis++;
                } else{
                    res_node = res_node->next;
                }
                if(res_node==pre_node){
                    return res_node;
                }

            }
        }
    }
};