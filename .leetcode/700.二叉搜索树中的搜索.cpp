/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {

        // 递归跳出条件
        // 情况一
        // 已经遍历到根节点类 不存在 没有该节点
        if (!root)
        {
            return nullptr;
        }

        // 情况二
        // 找到了该节点 则返回该节点即可
        if (root->val == val)
        {
            return root;
        }
        // 递归
        else if (root->val > val)
        {
            return searchBST(root->left, val);
        }
        else
        {
            return searchBST(root->right, val);
        }
    }
};
// @lc code=end
