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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr){return nullptr;}
       ListNode* ans=new ListNode(head->val);
       head=head->next;
       while(head!=nullptr){
        ListNode* curr=new ListNode(head->val);
        curr->next=ans;
        ans=curr;
        head=head->next;
       }
       return ans; 
    }
};
