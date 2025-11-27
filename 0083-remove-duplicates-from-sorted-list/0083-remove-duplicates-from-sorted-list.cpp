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
    ListNode* deleteDuplicates(ListNode* head) {
        // If the list is empty or has only one node, return it as is
        if (!head || !head->next) return head;
        
        ListNode* current = head;
        
        // Traverse the list
        while (current && current->next) {
            // If the current node and the next node have the same value
            if (current->val == current->next->val) {
                // Skip the next node
                current->next = current->next->next;
            } else {
                // Otherwise, move to the next node
                current = current->next;
            }
        }
        
        return head;
    }
};