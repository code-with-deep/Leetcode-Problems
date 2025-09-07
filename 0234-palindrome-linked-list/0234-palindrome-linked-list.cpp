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
    // function to reverse a linked list
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        // Step 1: Find middle using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* newHead = reverseLinkedList(slow->next);

        // Step 3: Compare the two halves
        ListNode* first = head;
        ListNode* second = newHead;
        while (second != nullptr) {
            if (first->val != second->val) {
                reverseLinkedList(newHead); // restore list before returning
                return false;
            }
            first = first->next;
            second = second->next;
        }

        // Step 4: Restore the original list
        reverseLinkedList(newHead);
        return true;
    }
};
