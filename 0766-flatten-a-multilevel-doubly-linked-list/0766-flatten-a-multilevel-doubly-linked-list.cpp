/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        
        Node* curr = head;
        
        while (curr) {
            if (curr->child) {
                Node* child = curr->child;
                
                while (child->next) {
                    child = child->next;
                }
                
                Node* next_node = curr->next;
                
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
                
                child->next = next_node;
                if (next_node) {
                    next_node->prev = child;
                }
            }
            
            curr = curr->next;
        }
        
        return head;
    }
};
