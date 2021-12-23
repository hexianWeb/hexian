#include <queue>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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

// 算法思想
// 方法一
// 既然只是验证平衡二叉树
// 那么如果使用BFS 在遇到一个叶子节点后 该层的所有节点又应该只有一层叶子节点了
// 即为后序遍历的程序节点都应该只有一层节点 度为1
// 整活版 哈哈哈哈

// 方法二
// 递归判断二叉树 树本身就具有递归性质
// 只需要判断
// 1.左子树 是否平衡
// 2.右子树 是否平衡
// 3. 左子树.高度 与 右子树.高度 差值是在1以内
// 递归三步
// 1. 参数 节点
//    返回值 当前节点是否为二叉树 以及当前二叉树的高度
// 2.终止条件
//      1） 当树为空是 return （true 0）；
//      2） 当 树不为空时 return (左子树是否平衡&&右子树是否平衡，当前树的高度)
// 3.单步逻辑
// 查看树是否平衡 计算树的高度并且返回

class Solution
{
    // 定义一个返回用的结构体
private:
    class ReturnType
    {
    public:
        bool isBalanced;
        int height;
        ReturnType(bool isB, int hei)
        {
            this->isBalanced = isB;
            this->height = hei;
        }
    };

public:
    ReturnType process(TreeNode *cur)
    {
        if (cur == nullptr)
        {
            return ReturnType(true, 0);
        }
        ReturnType leftReturn = process(cur->left);
        ReturnType rightReturn = process(cur->right);

        int height = max(leftReturn.height, rightReturn.height) + 1;
        bool isBalanced = leftReturn.isBalanced && rightReturn.isBalanced && (abs(leftReturn.height - rightReturn.height) < 2);
        return ReturnType(isBalanced, height);
    }
    bool isBalanced(TreeNode *root)
    {
        return process(root).isBalanced;
    }
};
// @lc code=end
