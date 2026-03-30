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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* forward=head;
        ListNode* backward=head;
        for(int i=1;i<=n;i++){
            forward=forward->next;
        }
        ListNode* prev=nullptr;
        while(forward!=nullptr){
            forward=forward->next;
            prev=backward;
            backward=backward->next;
        }
        if(prev==nullptr){
        if(head->next==nullptr){return nullptr;}
        else{
            ListNode* ans=head->next;
            head=nullptr;
            return ans;
        }
        }else{
            if(backward->next==nullptr){
                prev->next=nullptr;
                return head;
            }else{
                ListNode* temp=backward->next;
                backward=nullptr;
                prev->next=temp;
                return head;
            }
        }
        return nullptr;
    }
};
