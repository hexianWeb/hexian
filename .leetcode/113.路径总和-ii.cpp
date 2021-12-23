#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
// 本题中因为求得路径中处理节点顺序和访问节点顺序一致 所有可以选用先序遍历
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
    void hasPathSum(TreeNode *cur, int targetSum, vector<int> &path, vector<vector<int>> &res)
    {
        // 找到路径
        if (0 == targetSum && !cur->left && !cur->right)
        {
            res.push_back(path);
            return;
        }
        // 直到叶子节点也没找到符合的对象
        if (!cur->left && !cur->right)
        {
            return;
        }
        if (cur->left)
        {
            path.push_back(cur->left->val);
            targetSum -= cur->left->val;
            // 递归
            hasPathSum(cur->left, targetSum, path, res);
            // 回溯
            targetSum += cur->left->val;
            path.pop_back();
        }
        if (cur->right)
        {
            path.push_back(cur->right->val);
            targetSum -= cur->right->val;
            // 递归
            hasPathSum(cur->right, targetSum, path, res);
            // 回溯
            targetSum += cur->right->val;
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        vector<vector<int>> res;
        if (!root)
        {
            return res;
        }
        path.push_back(root->val);
        hasPathSum(root, targetSum - root->val, path, res);
        return res;
    }
};
// @lc code=end
