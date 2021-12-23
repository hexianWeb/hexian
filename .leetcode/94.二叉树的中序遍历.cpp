#include <vector>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    void inorder(TreeNode *T, vector<int> &res)
    {
        if (!T)
        {
            return;
        }
        inorder(T->left, res);
        res.push_back(T->val);
        inorder(T->right, res);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        // 结果集
        vector<int> res;

        // 栈
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
                // 回溯
                stack.pop();
                if (cur->right)
                {
                    stack.push(cur->right);
                }

                stack.push(cur);
                stack.push(NULL);

                if (cur->left)
                {
                    stack.push(cur->left);
                }
            }
            // 处理节点
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
