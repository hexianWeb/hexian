#include <iostream>
using namespace std;

/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *A = headA;
        ListNode *B = headB;
        while (A != B)
        {
            A = A == nullptr ? headB : A->next;
            B = B == nullptr ? headA : B->next;
        }
        return A;
    }
};
// @lc code=end
