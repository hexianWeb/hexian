
/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
// 首先 构建二叉树时允许处理节点顺序与访问节点顺序一致 所以用前序遍历
// 方法一
// 递归法
// 1 参数 两个需要融合的节点 或右 或没有
//   返回 融合后创建的节点
// 2 终止条件
//      1） 左右同时右 返回 左+右
//      2） 左有右无 返回左
//      3） 左无右有 返回右
//      4） 左无右无 返回null
// 3 单层逻辑
// 判断各类终止条件
// 前序遍历向下递归创建二叉树
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        TreeNode *root = new TreeNode();
        if (!root1)
        {
            return root2;
        }
        if (!root2)
        {
            return root1;
        }
        root->val = root1->val + root2->val;

        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }
};
// @lc code=end
