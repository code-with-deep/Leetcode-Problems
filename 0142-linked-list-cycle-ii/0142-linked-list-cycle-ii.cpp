class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Find start of cycle
                ListNode* first = head;
                while (first != slow) {
                    first = first->next;
                    slow = slow->next;
                }
                return first;
            }
        }
        return NULL;
    }
};
