/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        // 递归函数终止条件 当节点为空的时候返回
        if (!root)
        {
            return nullptr;
        }
        TreeNode *temp = new TreeNode();
        // 交换节点 三步
        temp = root->right;
        root->right = root->left;
        root->left = temp;
        // 递归调用左右子树
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
// @lc code=end
