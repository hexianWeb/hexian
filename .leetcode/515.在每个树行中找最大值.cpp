#include <queue>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
// 使用BFS 层序遍历

class Solution
{
    // struct TreeNode
    // {
    //     int val;
    //     TreeNode *left;
    //     TreeNode *right;
    //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    //     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    // };

public:
    vector<int> largestValues(TreeNode *root)
    {
        // 层序遍历两件套
        queue<TreeNode *> queue;
        vector<int> ans = {};

        if (root)
        {
            queue.push(root);
        }

        while (!queue.empty())
        {
            /* code */
            int levelSize = queue.size();
            int maxNodeVal = -2147483648;
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *temp = queue.front();
                queue.pop();
                maxNodeVal = max(maxNodeVal, temp->val);

                if (temp->left)
                {
                    queue.push(temp->left);
                }
                if (temp->right)
                {
                    queue.push(temp->right);
                }
            }
            ans.push_back(maxNodeVal);
        }
        return ans;
    }
};
// @lc code=end
