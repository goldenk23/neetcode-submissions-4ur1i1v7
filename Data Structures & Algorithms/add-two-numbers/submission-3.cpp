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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int val= l1->val + l2->val;
      int carry=0;
      if(val>=10){
        val=val%10;
        carry=1;
      }
      l1=l1->next;
      l2=l2->next;
      ListNode* sum=new ListNode(val);
      ListNode* curr=sum;
      while(l1!=nullptr && l2!=nullptr){
        ListNode* next_node1=l1->next;
        ListNode* next_node2=l2->next;
         val= (l1->val + l2->val + carry);
         if(val>=10){carry=1;}
         else{carry=0;}
         curr->next=new ListNode((val%10));
         curr=curr->next;
         l1=next_node1;
         l2=next_node2;
      }
     while(l1){
        ListNode* next_node=l1->next;
        int val= l1->val + carry;
        if(val>=10){carry=1;}
        else{carry=0;}
       curr->next=new ListNode((val%10));
         curr=curr->next;
        l1=next_node;
     }
     while(l2){
        ListNode* next_node=l2->next;
        int val= l2->val + carry;
        if(val>=10){carry=1;}
        else{carry=0;}
       curr->next=new ListNode((val%10));
         curr=curr->next;
        l2=next_node;
     }
     if(carry){
        ListNode* last=new ListNode(carry);
        curr->next=last;
        curr=last;
     }
     return sum;
    }
};
