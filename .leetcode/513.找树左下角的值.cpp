#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
// 算法思想一
// 层序遍历
// 层序遍历该树
// // 每次遍历出现的第一个节点 然后反复覆盖 最后的结果返回即可
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
    int findBottomLeftValue(TreeNode *root)
    {
        // 建立辅助队列
        queue<TreeNode *> queue;
        if (root)
        {
            queue.push(root);
        }
        int ans = root->val;
        while (!queue.empty())
        {
            int levelSize = queue.size();
            ans = queue.front()->val;
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *cur = queue.front();
                queue.pop();
                if (cur->left)
                {
                    queue.push(cur->left);
                }
                if (cur->right)
                {
                    queue.push(cur->right);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
