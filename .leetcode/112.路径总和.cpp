#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        // 跳出递归的条件 分两种情况
        // 遍历到空节点 返回false（这种情况为了应对根节点为空 或左右子树不同时缺失的情况）
        if (!root)
        {
            return false;
        }
        cout << root->val << " ";
        // 向下层遍历 直到叶子节点
        // 查看当前叶子节点的值是否等于目标targerSum的值
        // 如果为真 则返回true 否则 返回false
        if (root->left == nullptr && root->right == nullptr)
        {
            return !(targetSum - root->val);
        }
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
// @lc code=end
