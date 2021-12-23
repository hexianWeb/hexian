/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
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
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// 思路 快慢指针
// 让快指针先向前移动N个距离
// 随后快慢指针同步移动
// 直到快指针到达表尾
class Solution
{

public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 设置虚拟头结点
        ListNode *dummyHead = new ListNode(0, head);

        ListNode *slow = dummyHead;
        ListNode *fast = dummyHead;

        for (int i = 0; i <= n; i++)
        {
            fast = fast->next;
        }
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // 删除节点
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};
// @lc code=end
