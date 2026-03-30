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
    ListNode* head=nullptr;
    ListNode* tail=nullptr;
public:
void insert_element( int val){
    ListNode* node=new ListNode(val);
    if(head==nullptr||val<=head->val){
       node->next=head;
       head=node;
       if(!tail){tail=node;}
       return;
    }
    if(val>=tail->val){
        tail->next=node;
        tail=node;
        return;
    }
    ListNode* it=head;
    while(it&&it->next->val<val){
        it=it->next;
    }
    node->next=it->next;
    it->next=node;
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        bool done=false;
        while(!done){
            done=true;
            for(int i=0;i<lists.size();i++){
                if(lists[i]){
                    insert_element(lists[i]->val);
                    lists[i]=lists[i]->next;
                    done=false;
                }
            }
        }
        return head;
    }
};
