#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
// 简单的层序遍历 每一层求平均值
class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        // 辅助队列 以及答案初始化
        queue<TreeNode *> queue;
        vector<double> ans;

        if (root)
        {
            queue.push(root);
        }
        while (!queue.empty())
        {
            int levelSize = queue.size();
            double sum = 0;
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *temp = queue.front();
                queue.pop();
                sum += temp->val;
                if (temp->left)
                {
                    queue.push(temp->left);
                }
                if (temp->right)
                {
                    queue.push(temp->right);
                }
            }
            ans.push_back(sum / levelSize);
        }
        return ans;
    }
};
// @lc code=end
