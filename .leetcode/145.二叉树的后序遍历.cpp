#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> stack;
        if (root)
        {
            stack.push(root);
        }
        while (!stack.empty())
        {
            if (stack.top() != NULL)
            {
                TreeNode *cur = stack.top();
                stack.pop();
                stack.push(cur);
                stack.push(NULL);

                if (cur->right)
                {
                    stack.push(cur->right);
                }

                if (cur->left)
                {
                    stack.push(cur->left);
                }
            }
            else
            {
                stack.pop();
                res.push_back(stack.top()->val);
                stack.pop();
            }
        }

        return res;
    }
};
// @lc code=end
