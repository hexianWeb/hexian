#include <vector>
#include <stack>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // 设立虚拟头结点
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *pre = dummyNode;
        ListNode *cur = dummyNode->next;

        // 指针移动到相应位置
        for (int step = 0; step < left - 1; step++)
        {
            pre = pre->next;
            cur = cur->next;
        }
        // 头插法插入
        for (int i = 0; i < right - left; i++)
        {
            ListNode *temp = cur->next;
            cur->next = cur->next->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return dummyNode->next;
    }
};
// @lc code=end
