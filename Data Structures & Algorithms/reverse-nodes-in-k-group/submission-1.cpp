/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        ListNode* prev_tail=nullptr;
        while(curr){
            ListNode* temp_head=curr;
        pair<ListNode*,ListNode*>p=reverse_section(curr,k);
        if(p.first==nullptr&&p.second==nullptr){break;}
        else{
           if(prev_tail){
            prev_tail->next=p.first;
           }else{
            head=p.first;
           }
           prev_tail=p.second;
           curr=p.second->next;
        }
        }
        return head;
    }
    pair<ListNode*,ListNode*> reverse_section(ListNode* head,int k){
            ListNode* temp=head;
            int x=k;
            while(x--){
                if(temp==nullptr){return {nullptr,nullptr};}
                temp=temp->next;
            }
     ListNode* node=nullptr;
      ListNode* tail=node;
      int count=0;
      while(k--){
        ListNode* next_node=head->next;
        head->next=node;
        node=head;
        if(!tail){tail=head;}
        count++;
        head=next_node;
      }
      tail->next=head;
      return {node,tail};  
    }
};
