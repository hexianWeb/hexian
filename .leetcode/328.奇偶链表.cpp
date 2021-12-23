/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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

// 奇数偶数链表
// 奇数链表走两步 偶数链表走两步
// 最后奇数偶数拼起来
class Solution
{
    // struct ListNode
    // {
    //     int val;
    //     ListNode *next;
    // };

public:
    ListNode *oddEvenList(ListNode *head)
    {
        // 若当前给的链表长度小于3 则无需处理 直接返回
        if (!head || !head->next)
        {
            return head;
        }
        // 先后记下 奇数偶数的前进工具节点 已经奇数偶数的起始节点
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *FirstNode = odd;
        ListNode *secondHead = even;
        while (even && even->next)
        {
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = secondHead;
        return FirstNode;
    }
};
// @lc code=end
