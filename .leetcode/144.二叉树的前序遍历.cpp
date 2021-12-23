#include <vector>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start

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
    void preorder(TreeNode *T, vector<int> &res)
    {
        if (!T)
        {
            return;
        }
        res.push_back(T->val);
        preorder(T->left, res);
        preorder(T->right, res);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        // 建立答案数组
        vector<int> res;
        // 建立辅助栈
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
                if (cur->right)
                {
                    stack.push(cur->right);
                }
                if (cur->left)
                {
                    stack.push(cur->left);
                }

                stack.push(cur);
                // 加入标记元素tag NULL
                stack.push(NULL);
            }
            // 遇到已经处理完毕的节点
            else
            {
                // 去除标记
                stack.pop();
                // 去除本体
                res.push_back(stack.top()->val);
                stack.pop();
            }
        }
        return res;
    }
};
// @lc code=end
