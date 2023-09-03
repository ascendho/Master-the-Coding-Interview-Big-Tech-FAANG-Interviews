#ifndef INC_09_CYCLE_DETECTION_SOLUTION_H
#define INC_09_CYCLE_DETECTION_SOLUTION_H

/* Definition for singly-linked list. */

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle_Floyd(ListNode *head);

ListNode *detectCycle_HashMap(ListNode *head);

#endif //INC_09_CYCLE_DETECTION_SOLUTION_H