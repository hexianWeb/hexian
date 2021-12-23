#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start

// Definition for a Node.
// 本质与二叉树的层序遍历没有区别
// 知识在子节点入栈时需要改动
// class Node
// {
// public:
//     int val;
//     vector<Node *> children;

//     Node() {}

//     Node(int _val)
//     {
//         val = _val;
//     }

//     Node(int _val, vector<Node *> _children)
//     {
//         val = _val;
//         children = _children;
//     }
// };

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        // 初始化队列 以及答案数组
        queue<Node *> queue;
        vector<vector<int>> ans;

        if (root)
        {
            queue.push(root);
        }

        // 当队列值不为空时
        while (!queue.empty())
        {
            int levelSize = queue.size();
            vector<int> son_ans;
            for (int i = 0; i < levelSize; i++)
            {
                Node *temp = queue.front();
                queue.pop();
                son_ans.push_back(temp->val);
                for (Node *node : temp->children)
                {
                    queue.push(node);
                }
            }
            ans.push_back(son_ans);
        }
        return ans;
    }
};
// @lc code=end
