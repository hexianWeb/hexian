#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
// // Definition for a Node.
// class Node
// {
// public:
//     int val;
//     Node *left;
//     Node *right;
//     Node *next;

//     Node() : val(0), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val, Node *_left, Node *_right, Node *_next)
//         : val(_val), left(_left), right(_right), next(_next) {}
// };
// 解法一 基础解法
// 算法思想
// 该题依然是一个典型的BFS
// 层序遍历 查找每一层的节点
// 队列中的节点依次遍历 前者用容器存储 后再经过时 前者指向后者 没有则指向空

class Solution
{
public:
    Node *connect(Node *root)
    {
        // BFS 队列
        queue<Node *> queue;

        if (root)
        {
            queue.push(root);
        }

        while (!queue.empty())
        {
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++)
            {
                Node *bro = queue.front();
                queue.pop();
                // 情况一 无后继结点
                if (i == levelSize - 1)
                {
                    bro->next = nullptr;
                }
                else
                {
                    // 情况二 后继结点存在
                    Node *cur = queue.front();
                    bro->next = cur;
                }
                if (bro->left)
                {
                    queue.push(bro->left);
                }
                if (bro->right)
                {
                    queue.push(bro->right);
                }
            }
        }
        return root;
    }
};
// @lc code=end
