#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
// 方法一
// 线索二叉树本身就是一个高效的有序数组
// 在针对此类题目没有思路时 不妨试试转换成有序数组再开始解决问题
// 如将线索二叉树转换为有序数组后 每次比较(前一个元素-当前元素的值) 保存最小绝对差

// 方法二
// 中序遍历线索二叉树
// 在递归中记录前一个节点值指针
// 每次到一个新节点后 用前一个节点指针-当前节点指针
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution
{
public:
    int min_Value = __INT16_MAX__;
    TreeNode *pre;
    void traversal(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        traversal(root->left);

        if (pre)
        {
            min_Value = min(min_Value, root->val - pre->val);
        }
        pre = root;

        traversal(root->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        traversal(root);

        return min_Value;
    }
};
// @lc code=end
