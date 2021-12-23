#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
// 方法三
// 二分查找配合位运算
// 因为完全二叉树，叶子节点只会出现在最后两层
// 那么当树的左右子树右以下两种情况
// 1.左子树==右子树 ==》 可以确认左子树为满二叉树  此时递归调用函数本身 计算右子树的节点数量
// 2. 左子树！=右子树 ==》 当前树倒数第二层满 最后一层不满 可以确认右子树为满二叉树 计算左子树的节点数量
// 递归三步
// 1） 参数 当前树的根节点
//     返回值 当前树的节点个数
// 2） 终止条件
//      1.如果当前根节点为空  树的个数为0 return 0
//      2.当前左子树深度等于右子树 则 return 2^左子树深度（左子树一定为满）-1+根节点+ countNode（右子树）
//      3.当前左子树深度不等于右子树深度 则 return 2^右子树深度（右子树一定为满）-1+根节点+countNode（左子树）
// 3）单层逻辑
// 判断当前节点
// 1.左子树==右子树 ==》 可以确认左子树为满二叉树  此时递归调用函数本身 计算右子树的节点数量
// 2. 左子树！=右子树 ==》 当前树倒数第二层满 最后一层不满 可以确认右子树为满二叉树 计算左子树的节点数量
// 若不存在左右子树 返回0
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftLevel = countLevel(root->left);
        int rightLevel = countLevel(root->right);
        if (leftLevel == rightLevel)
        {
            return (1 << leftLevel) + countNodes(root->right);
        }
        else
        {
            return (1 << rightLevel) + countNodes(root->left);
        }
    }

    // 完全二叉树计算层数的方式
    // 因为不存在 有右无左的方式 所有这样即可探究深度
    int countLevel(TreeNode *root)
    {
        int level = 0;
        while (root != nullptr)
        {
            level++;
            root = root->left;
        }
        return level;
    }
};
// @lc code=end
