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
        return getSum(l1,l2);
    }
    void listReverse(ListNode *a,ListNode* pre,ListNode* &re){
    if(a== nullptr){
        return;
    }
    if(a->next==nullptr){
        a->next = pre;
        re = a;
        return;
    }
    listReverse(a->next,a,re);
    a->next = pre;
}
    ListNode* getSum(ListNode* a,ListNode* b) {

    ListNode* head;
    ListNode* ra;
    ListNode* it;
    ListNode* rb;
    listReverse(a,nullptr,ra);
    listReverse(b,nullptr,rb);
    ListNode* tmpre;
    head = tmpre;
    bool cnt = false;
    bool first = false;
    while(ra!=nullptr&&rb!=nullptr){

        int val = (ra->val+rb->val+cnt)%10;


        tmpre = new ListNode(val);
        if(!first){
            first = true;
            it = tmpre;
            head = it;
        }else{
            it->next = tmpre;
            it = tmpre;
        }
        cnt = (ra->val+rb->val+cnt)/10;
                ra = ra->next;
        rb = rb->next;
    }

    ListNode* rest;
    if(ra!=nullptr){
        rest = ra;
    }else if(rb!=nullptr){
        rest = rb;
    }else{
        
    }

    while(rest!=nullptr){
        tmpre = new ListNode((rest->val+cnt)%10);
        it->next = tmpre;
        cnt = (rest->val+cnt)/10;
        it = tmpre;
        rest = rest->next;
    }
    if(cnt){
         tmpre = new ListNode(1);
         it->next = tmpre;
         it = tmpre;
    }

    ListNode* res;
    listReverse(head,nullptr,res);
    return res;

}
};