#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
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
    // 递归三要素
    // 参数以及返回值 参数已经规定是当前子树的根节点
    // 返回值依据题意应该是当前整颗子树的最大深度
    // 终止条件
    // 当节点为空时 返回深度为0
    // 递归形式 当前整颗树当前子树最大深度+1
    int maxDepth(TreeNode *root)
    {
        return !root ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
    };
    // 方法二：广度优先遍历
    // BFS Thinking
    // 每次向下探索一层的时候 将一整层的节点拉入queue中
    // 随后遍历queue中所有的节点 依次重复这两个步骤 以确保所有的节点都能被探索到
    int maxDepth2(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        queue<TreeNode *> queue;
        queue.push(root);
        int ans = 0;
        while (!queue.empty())
        {
            int NodeNums = queue.size();
            while (NodeNums > 0)
            {
                TreeNode *node = queue.front();
                queue.pop();
                if (node->left)
                {
                    queue.push(node->left);
                }
                if (node->right)
                {
                    queue.push(node->right);
                }
                NodeNums--;
            }
            ans++;
        }
        return ans;
    }
};
// @lc code=end
