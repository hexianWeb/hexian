#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
// Definition for a Node.
// class Node
// {
// public:
// int val;
// vector<Node *> neighbors;
// Node()
// {
//     val = 0;
//     neighbors = vector<Node *>();
// }
// Node(int _val)
// {
//     val = _val;
//     neighbors = vector<Node *>();
// }
// Node(int _val, vector<Node *> _neighbors)
// {
//     val = _val;
//     neighbors = _neighbors;
// }
// };

class Solution
{
private:
    unordered_map<Node *, Node *> hash;

public:
    Node *clone(Node *node)
    {
        // 如果该节点已经被访问过，可以直接从克隆节点中返回
        if (hash[node])
        {
            return hash[node];
        }

        // 未访问过 克隆节点
        Node *NewNode = new Node(node->val);
        // 节点放入集合
        hash[node] = NewNode;
        for (Node *ver : node->neighbors)
        {
            NewNode->neighbors.push_back(clone(ver));
        }
        return NewNode;
    }
    Node *cloneGraph(Node *node)
    {
        if (!node)
        {
            return NULL;
        }
        return clone(node);
    }
};
// @lc code=end
