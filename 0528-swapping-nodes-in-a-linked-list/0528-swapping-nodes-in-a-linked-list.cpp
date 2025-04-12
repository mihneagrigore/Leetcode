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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* current = head;
        int length = 0;
        while (current != nullptr) {
            length++;
            current = current->next;
        }

        ListNode* node1 = head;
        for (int i = 1; i < k; ++i) {
            node1 = node1->next;
        }

        ListNode* node2 = head;
        for (int i = 1; i < length - k + 1; ++i) {
            node2 = node2->next;
        }

        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;

        return head;
    }
};
