#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
// 这题和平时遇到的整数加法类似 需要专门设置变量考虑进位 以及补0

class Solution
{
private:
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // 是否进位标识符
        int carry = 0;
        ListNode *head = new ListNode(0);
        ListNode *prev = head;
        while (l1 || l2)
        {
            int sum = 0;
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            // 当期是否进位判断
            if (sum >= 10)
            {
                sum = sum % 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            // 尾插法建立节点
            ListNode *cur = new ListNode(sum);
            prev->next = cur;
            prev = prev->next;
        }
        // 是否需要进位
        if (carry)
        {
            prev->next = new ListNode(1);
        }

        return head->next;
    }
    // struct ListNode
    // {
    //     int val;
    //     ListNode *next;
    //     ListNode() : val(0), next(nullptr) {}
    //     ListNode(int x) : val(x), next(nullptr) {}
    //     ListNode(int x, ListNode *next) : val(x), next(next) {}
    // };
};
// @lc code=end
