
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
// 方法一 递归法
// 首先确定递归三要素
// 1.函数主题的参数以及返回类型
// 此题中判断左右子树是否对称 参数自然是 左子树 和 右子树
// 返回类型 是bool值
// 2.确定终止条件
// 比较左右子树 会出现三种情况
// 1） 左子树 与 右子树 都存在 值相同则为true 不同则为false
// 2） 左子树 右子树 都不存在 则 为true
// 3） 左子树 右子树 其中之一存在 false
// 3.确定单层递归逻辑
// 比较当前两颗树是否对称
// 比较树一的左子树与树二的右子树是否对称
// 比较树一的右子树与树二的左子树是否对称
// 比较树一与树二的值是否对称
class Solution
{
public:
    bool isSTT(TreeNode *lchild, TreeNode *rchild)
    {
        if (!lchild && !rchild)
        {
            return true;
        }
        else if (!lchild || !rchild)
        {
            return false;
        }
        return (lchild->val == rchild->val ? true : false) && isSTT(lchild->left, rchild->right) && isSTT(lchild->right, rchild->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        return isSTT(root->left, root->right);
    }
};
// @lc code=end
