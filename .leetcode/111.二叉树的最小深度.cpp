#include <algorithm>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
// 方法二
// 直接上BFS
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
private:
    int depth = 0;

public:
    int minDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        if (root->left == nullptr && root->right != nullptr)
        {
            return minDepth(root->right) + 1;
        }
        if (root->left != nullptr && root->right == nullptr)
        {
            return minDepth(root->left) + 1;
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
    int minDepth2(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int depth = 0;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            depth++; // 记录最小深度
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
                if (!node->left && !node->right)
                { // 当左右孩子都为空的时候，说明是最低点的一层了，退出
                    return depth;
                }
            }
        }
        return depth;
    }
};

// @lc code=end
