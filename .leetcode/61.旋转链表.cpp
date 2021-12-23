#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        int length = 0;
        // 排除空链表带来空指针影响
        if (!head)
        {
            return head;
        }
        // 快慢指针
        ListNode *slow = head;
        ListNode *fast = head;

        // 计算总长度
        while (slow)
        {
            length++;
            slow = slow->next;
        }
        slow = head;
        // 步长除余 省去多余移动
        int step = k % length;
        // 步长可被长度整除 无需进行调整 直接返回即可
        if (step == 0)
        {
            return head;
        }
        // 快指针先走step步
        while (step--)
        {
            fast = fast->next;
        }
        // 满指针与快指针同步移动
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *dummyHead = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return dummyHead;
    }
};
// @lc code=end
