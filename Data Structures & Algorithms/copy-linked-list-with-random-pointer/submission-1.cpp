/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> find_pos;
        int pos = 1;
        Node* temp = head;
        while (temp != nullptr) {
            find_pos[temp] = pos;
            temp = temp->next;
            pos++;
        }
        unordered_map<Node*, int> find_rand_pos;
        Node* curr = head;
        Node* clone_head = nullptr;
        Node* clone_tail = nullptr;
        while (curr != NULL) {
            if (curr->random == nullptr) {
                find_rand_pos[curr] = 0;
            } else {
                find_rand_pos[curr] = find_pos[curr->random];
            }
            if (clone_head == nullptr && clone_tail == nullptr) {
                clone_head = new Node(curr->val);
                clone_tail = clone_head;
            } else {
                Node* temp = new Node(curr->val);
                clone_tail->next = temp;
                clone_tail = temp;
            }
            curr = curr->next;
        }
        // map each pos in cloned linked list to its corresponding node
        unordered_map<int, Node*> mp;
        Node* temp_clone = clone_head;
        int pos1 = 1;
        while (temp_clone != nullptr) {
            mp[pos1] = temp_clone;
            temp_clone = temp_clone->next;
            pos1++;
        }
        Node* curr_original = head;
        Node* curr_clone = clone_head;
        while (curr_original != nullptr && curr_clone != nullptr) {
            int target_pos = find_rand_pos[curr_original];
            if (target_pos == 0) {
                curr_clone->random = nullptr;
            } else {
                curr_clone->random = mp[target_pos];
            }
            curr_original = curr_original->next;
            curr_clone = curr_clone->next;
        }

        return clone_head;
    }
};
