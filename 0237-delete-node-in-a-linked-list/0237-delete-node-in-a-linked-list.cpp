/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy value from next node to current
        node->val = node->next->val;
        // Skip the next node
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp; // free temp
    }
};
