#include <vector>
#include <list>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> queue;
        vector<vector<int>> ans;
        if (root != NULL)
        {
            queue.push(root);
        }
        else
        {
            return {};
        }
        while (!queue.empty())
        {
            int num = queue.size();
            // 依次获取当前节点 并将他们的左右孩子纳入queue中
            vector<int> LevelNodes;
            for (int i = 0; i < num; i++)
            {
                TreeNode *node = queue.front();
                queue.pop();
                LevelNodes.push_back(node->val);
                if (node->left != NULL)
                {
                    queue.push(node->left);
                }
                if (node->right != NULL)
                {
                    queue.push(node->right);
                }
            }
            ans.push_back(LevelNodes);
        }
        return ans;
    }
};
// @lc code=end
