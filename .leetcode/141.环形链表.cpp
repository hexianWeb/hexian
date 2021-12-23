/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
    // struct ListNode
    // {
    //     int val;
    //     ListNode *next;
    //     ListNode(int x) : val(x), next(nullptr) {}
    // };

public:
    bool hasCycle(ListNode *head)
    {
        // Initialize slow & fast pointers
        ListNode *slow = head;
        ListNode *fast = head;
        /**
 * Change this condition to fit specific problem.
 * Attention: remember to avoid null-pointer error
 **/
        while (slow && fast && fast->next)
        {
            slow = slow->next;       // move slow pointer one step each time
            fast = fast->next->next; // move fast pointer two steps each time
            if (slow == fast)
            { // change this condition to fit specific problem
                return true;
            }
        }
        return false; // change return value to fit specific problem
    }
};
// @lc code=end
