#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
// 右视图 即可看做是BFS 过程中 每层出现的最后一个节点
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
    vector<int> rightSideView(TreeNode *root)
    {
        queue<TreeNode *> queue;
        // 答案数组
        vector<int> ans;

        // 初始化 准备开始
        if (root)
        {
            queue.push(root);
        }

        // BFS 遍历 按层数分隔 遍历到最后一个节点拉入ans数组
        while (!queue.empty())
        {
            // 单层节点个数
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *temp = queue.front();
                queue.pop();
                if (temp->left)
                {
                    queue.push(temp->left);
                }
                if (temp->right)
                {
                    queue.push(temp->right);
                }
                // 做判断 获取最后节点
                if (i == levelSize - 1)
                {
                    ans.push_back(temp->val);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
