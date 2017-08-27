class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        for(auto it:lists){
            res = merge(res,it);
        }
        return res;
    }
    ListNode* merge2Lists(ListNode* a,ListNode* b){

        ///@note nullptr pointer
        ListNode* res = nullptr;
        if(a== nullptr){
            return b;
        } else if(b== nullptr){
            return a;
        } else {
            if(a->val<b->val){
                res = a;
                a = a->next;
            } else{
                res = b;
                b = b->next;
            }
            ListNode* tmp = res;
            while (a!= nullptr&&b!= nullptr){
                if(a->val<b->val){
                    tmp->next = a;
                    a = a->next;
                } else{
                    tmp->next = b;
                    b = b->next;
                }
                tmp = tmp->next;
            }
            if(a!= nullptr){
                tmp->next = a;
            }else{
                tmp->next = b;
            }
            return res;
        }

    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val < l2->val){
            l1->next = merge(l1->next, l2);
            return l1;
        }else{
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};