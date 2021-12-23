#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        // 层序遍历辅助队列
        queue<TreeNode *> queue;
        // 答案队列
        vector<vector<int>> ans;

        // 初始化 准备开始
        // 保证程序健壮性
        if (root)
        {
            queue.push(root);
        }

        while (!queue.empty())
        {
            int levelSize = queue.size();
            vector<int> son_size;
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *temp = queue.front();
                son_size.push_back(temp->val);
                queue.pop();
                if (temp->left)
                {
                    queue.push(temp->left);
                }
                if (temp->right)
                {
                    queue.push(temp->right);
                }
            }
            ans.push_back(son_size);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
