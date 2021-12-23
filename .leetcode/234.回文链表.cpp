#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
class Solution

{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
        {
            return true;
        }

        // 规定快慢指针
        ListNode *slow = head;
        ListNode *fast = head;
        // 前半段指针逆转 所以表尾节点指向空指针
        ListNode *pre = head;
        ListNode *prepre = nullptr;

        // 如
        // null 1->2->3->4
        // null<-1<-2  3->4->null
        // 快慢指针+反转链表操作
        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
            pre->next = prepre;
            prepre = pre;
        }

        // 跳出循环时fast存在当前节点为奇数个 slow需要向前移动 确保回文如 【1，0，1】成立
        if (fast)
        {
            slow = slow->next;
        }

        while (pre && slow)
        {
            if (pre->val != slow->val)
            {
                return false;
            }
            pre = pre->next;
            slow = slow->next;
        }
        return true;
    }
};
// @lc code=end
