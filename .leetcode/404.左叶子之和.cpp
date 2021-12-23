/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// 算法思想
// 每棵树的左叶子之和=这棵树的左子树的左叶子之和+这颗树的右叶子之和
// 获取顺序为 左 右 根
// 故此题采取后序遍历
// 递归三步
// 1. 参数 当前节点
//      返回值 当前节点的左叶子之和
// 2.终止条件
//      CASE1： 当当前节点不存在 则左叶子之和为0 return0
//      CASE2： 当前节点存在 若当前节点为叶子节点则返回该节点的值 否则则返回 当前节点左叶子之和的值
//  3. 单层递归逻辑
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        // 终止条件一
        if (!root)
        {
            return 0;
        }
        int leftLeftSum = sumOfLeftLeaves(root->left);
        int rightLeftSum = sumOfLeftLeaves(root->right);

        int midValue = 0;
        // 当前节点为叶子节点 终止条件二
        if (root->left && !root->left->left && !root->left->right)
        {
            midValue = root->left->val;
        }

        // 不然则返回当前节点的左叶子节点之和
        return leftLeftSum + midValue + rightLeftSum;
    }
};
// @lc code=end
