#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
// 算法思路
// 若L1 L2中 有一个链表为空
// 则返回L1或L2中不空的链表
//  构建指针preprev节点
// 让preprev节点指向较为小的那一个
// 随后 pre指针和较小指针向后移动一位
// 依次类推
// 直到一个链表完全遍
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// 递归的算法思想
// 每次都选出当前两个链表中最小的节点，让它的next指针指向下一个两个链表中最小的节点
// 一、递归函数的参数和返回值
// 1.参数： 就应该是两个即将要比较并得出当前最小节点的链表
// 2.返回值是当前最小的节点
// 二、递归的终止条件
// 两个链表在比较过程中，有一方不能在继续比较下去（节点耗尽）
// 三、递归的单层逻辑
// 比较两个链表当前头结点的大小，得出的最小节点让其指向下一次递归调用的最小节点。
class Solution
{
private:
    // 黑盒函数实现
    ListNode *getMin(ListNode *l1, ListNode *l2)
    {

        if (l1->val <= l2->val)
        {
            return l1;
        }
        else
        {
            return l2;
        }
    };

public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // 终止条件
        if (!l1 || !l2)
        {
            return l1 == nullptr ? l2 : l1;
        }
        // 单层逻辑
        ListNode *temp = getMin(l1, l2);
        temp->next = temp == l1 ? mergeTwoLists(l1->next, l2) : mergeTwoLists(l2->next, l1);

        return temp;
    }
};
// @lc code=end
