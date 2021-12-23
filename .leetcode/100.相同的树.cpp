#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//算法思想
// 典型的树形DP问题
// 直接上递归三步
// 1， 参数 对比左右子树是否相同 参数 左子树 右子树
//     返回类型 bool类型
// 2.终止条件
// 比较左右子树 会出现三种情况
// 1） 左子树 与 右子树 都存在 值相同则为true 不同则为false
// 2） 左子树 右子树 都不存在 则 为true
// 3） 左子树 右子树 其中之一存在 false
// 3.单层递归逻辑
// 比较两树的子树是否相同
//  比较当前节点是否相同
// 代码优化 2.0班
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
        {
            return true;
        }
        else if (!p || !q)
        {
            return false;
        }
        return (p->val == q->val ? true : false) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
// @lc code=end
