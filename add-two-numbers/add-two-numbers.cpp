/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* head;
    ListNode* p = new ListNode(0);
    head = p;
    int pass = 0;
    while (l1!= nullptr&&l2!= nullptr){
        ListNode* tmp = new ListNode((l1->val+l2->val+pass)%10);
        p->next = tmp;
        p = tmp;
        pass = (l1->val+l2->val+pass)/10;
        l1 = l1->next;
        l2 = l2->next;
    }
    bool ok = false;
    if(l1== nullptr&&l2== nullptr){
        ok = true;
        if(pass>0){
            ListNode* tmp = new ListNode(pass%10);
            p->next = tmp;
        }
    } else if(l1!= nullptr){

    } else if(l2!= nullptr){
//        cout<<"ok"<<endl;
        l1 = l2;
    } else;
    if(!ok){
        assert(l1!= nullptr);
        p->next = l1;
        int tmp = pass;
        pass = (l1->val+pass)/10;
        l1->val = (l1->val+tmp)%10;
        ListNode* pre = l1;
        l1 = l1->next;

        while (pass>0&&l1!= nullptr){
            l1->val = l1->val+pass;
            pass = (l1->val)/10;
            l1->val%=10;
            pre = l1;
            l1 = l1->next;
        }
        if(pass){
            ListNode* fin = new ListNode(pass%10);
            pre->next = fin;
        }
    }

    return head->next;
    }
};