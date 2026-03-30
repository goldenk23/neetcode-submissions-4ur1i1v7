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
    void reorderList(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* ptr1=nullptr;
        ListNode* curr1=slow->next;
        slow->next=nullptr;
        while(curr1!=nullptr){
            ListNode* next_node=curr1->next;
            curr1->next=ptr1;
            ptr1=curr1;
            curr1=next_node;
        }
        ListNode* curr2=head;
        while(curr2!=slow->next&&ptr1!=nullptr){
            ListNode* next_node2=curr2->next;
            ListNode* next_node1=ptr1->next;
            curr2->next=ptr1;
            ptr1->next=next_node2;
            curr2=next_node2;
            ptr1=next_node1;
        }
    }
};
