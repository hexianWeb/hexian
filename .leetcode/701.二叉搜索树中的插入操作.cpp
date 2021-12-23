/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
 */

// @lc code=start

//   Definition for a binary tree node.
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
// 因为题目中给出了新值和原始二叉搜索树中的任意节点值都不同
// 所以本质上其实不需要我去建立根堆 之类的操作
// 只需要比对并找到合适这个节点的位置然后插入即可
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // 找到该节点
        if (!root)
        {
            TreeNode *node = new TreeNode(val);
            return node;
        }
        if (root->val < val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        else
        {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};
// @lc code=end
