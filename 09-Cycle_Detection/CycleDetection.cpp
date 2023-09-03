#include "CycleDetection.h"
#include <unordered_set>

// Floyd环路检测算法

// 时间复杂度: O(n)
// 空间复杂度: O(1)

ListNode *detectCycle_Floyd(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    // slow指针每次移动1步, fast指针每次移动2步
    // 直到它们相遇或者快指针到达链表的尾部

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // 如果两指针相遇, 则该链表存在环路
            // 重置slow指针指向链表头部, 并每次移动两指针1步, 直到它们再次相遇
            // 且相遇的结点就是环路的起始结点

            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    // 如果fast指针在未与slow指针相遇前到达链表尾部, 则该链表不存在环路
    return nullptr;
}

// 哈希表算法

// 时间复杂度: O(n)
// 空间复杂度: O(n)

ListNode *detectCycle_HashMap(ListNode *head) {
    std::unordered_set<ListNode *> visited;

    // 遍历链表中的每个结点
    while (head != nullptr) {

        // 遇到此前遍历过的结点, 则可判断存在环路且该结点就是环路的起始结点
        if (visited.count(head)) {
            return head;
        }

        // 记录此前未遇到过的结点
        visited.insert(head);
        head = head->next;
    }

    return nullptr;
}