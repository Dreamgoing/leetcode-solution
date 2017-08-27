class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
      if(head==nullptr){
        return nullptr;
      }
      map<RandomListNode*,RandomListNode*> mp;
      mp[nullptr] = nullptr;
      mp.clear();
      RandomListNode* old_it = head->next;
      RandomListNode* res = new RandomListNode(head->label);
      RandomListNode* new_it = res;
      mp[head] = res;
      while (old_it!=nullptr) {
        RandomListNode* node = new RandomListNode(old_it->label);
        mp[old_it] = node;
        new_it->next = node;
        new_it = new_it->next;
        old_it = old_it->next;
      }
      old_it = head;
      new_it = res;
      while (old_it!=nullptr) {
        new_it->random = mp[old_it->random];
        old_it = old_it->next;
        new_it = new_it->next;
      }
      return res;

    }
};