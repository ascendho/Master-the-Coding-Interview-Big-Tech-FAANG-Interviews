#include "Solution.h"
#include <unordered_set>

ListNode *detectCycle_Floyd(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    // Move the slow pointer one step and the fast pointer two steps at a time through the linked list,
    // until they either meet or the fast pointer reaches the end of the list.
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // If the pointers meet, there is a cycle in the linked list.
            // Reset the slow pointer to the head of the linked list, and move both pointers one step at a time
            // until they meet again. The node where they meet is the starting point of the cycle.
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    // If the fast pointer reaches the end of the list without meeting the slow pointer,
    // there is no cycle in the linked list. Return nullptr.
    return nullptr;
}

ListNode *detectCycle_HashMap(ListNode *head) {
    std::unordered_set<ListNode *> visited;
    while (head != nullptr) {
        if (visited.count(head)) {
            return head;
        }
        visited.insert(head);
        head = head->next;
    }

    return nullptr;
}