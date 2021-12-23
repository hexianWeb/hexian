#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
// 树形DP 递归验证
// 递归三步
// 1） 参数 当前树
//     返回值 当前树是否为二叉树
// 2）终止条件
// 空节点本身为true
// 当前节点的值小于直接前驱的值 则不符合搜索二叉树的特点

// 方法二
// 转换数组
// 搜索树性质 递增排序验证
// 搜索树的性质简单归纳为 ： 左<根<右
// 中序遍历处理节点顺序一致 中序输出后为递增序列
// 故：
//
class Solution
{
public:
    vector<int> inorder;
    void traversal(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        traversal(root->left);
        inorder.push_back(root->val);
        traversal(root->right);
    }
    bool isValidBST(TreeNode *root)
    {
        traversal(root);
        for (int i = 1; i < inorder.size(); i++)
        {
            if (inorder[i] <= inorder[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
