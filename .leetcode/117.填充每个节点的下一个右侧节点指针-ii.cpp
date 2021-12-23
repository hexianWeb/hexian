/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

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
