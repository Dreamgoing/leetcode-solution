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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr&&l2==nullptr){
            return nullptr;
        }else if(l1==nullptr){
            return l2;
        }else if(l2==nullptr){
            return l1;
        }
        ListNode* fake = new ListNode(0);
        ListNode* it = fake;
        while(l1!=nullptr&&l2!=nullptr){
            if(l1->val<l2->val){
                it->next = l1;
                l1 = l1->next;
            }else{
                it->next = l2;
                l2 = l2->next;
            }
            it = it->next;
        }
        if(l1!=nullptr){
            it->next = l1;
        }else{
            it->next = l2;
        }
        return fake->next;
    }
};