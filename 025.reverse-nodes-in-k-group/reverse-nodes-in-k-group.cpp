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
     ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res = head;
        ListNode* tmp = head;
        ListNode* segHead = nullptr;
        ListNode* segTail = nullptr;
        int len = 0;
        while (tmp!= nullptr){
            tmp=tmp->next;
            len++;
        }
        int seg = len/k;

        int num = 0;
        tmp = head;
        vector<ListNode*> tmpli;
        for(int i = 0;i<seg;i++){
            num = 0;
            tmpli.clear();
            while (num<k){
                tmpli.push_back(tmp);
                tmp=tmp->next;
                num++;
            }
            reverseConnect(tmpli);
            if(segTail!= nullptr)
                segTail->next = tmpli.back();
            segTail = tmpli[0];
            segHead = tmpli.back();
            if(i==0){
                res = segHead;
            }

        }
        if(segTail!= nullptr){
            if(len%k==0){
                segTail->next = nullptr;
            } else{
                segTail->next = tmp;
            }
        }

        return res;

    }
    void reverseConnect(vector<ListNode*>& li){
        int len = (int)li.size();
        for(int i = len-1;i>0;i--){
            li[i]->next = li[i-1];
        }
    }
};