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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){return list2;}
        if(list2==nullptr){return list1;}
        ListNode* head=nullptr;
        ListNode* tail=head;
        ListNode* curr1=list1;
        ListNode* curr2=list2;
        while(curr1!=nullptr&&curr2!=nullptr){
            if(curr1->val<=curr2->val){
                ListNode* next_node1=curr1->next;
                curr1->next=nullptr;
                if(tail==nullptr){
                    head=curr1;
                    tail=curr1;
                }
                else{
                tail->next=curr1;
                tail=curr1;
                }
                curr1=next_node1;
            }else{
                ListNode* next_node2=curr2->next;
                curr2->next=nullptr;
                if(tail==nullptr){
                    head=curr2;
                    tail=curr2;
                }else{
                tail->next=curr2;
                tail=curr2;
                }
                curr2=next_node2;
            }
        }
        if(curr1!=nullptr){
            tail->next=curr1;
        }else if(curr2!=nullptr){
            tail->next=curr2;
        }
        if(head==nullptr){return nullptr;}
        return head; 
    }
};
