#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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

// 方法二
// 配合BFS一层一层向下开始遍历
// 将每一层的节点都拉入一个队列
// 循环遍历该队列各节点的值 并查看是否有符合 target -node->val =k的情况
// 重复上述步骤直到最后一层叶子节点再无节点添加
class Solution
{
private:
    // 记录出现过的节点

public:
    // 方法调用set集合需要使用&地址符号

    bool findTarget(TreeNode *root, int k)
    {
        unordered_set<int> set;
        queue<TreeNode *> queue;
        queue.push(root);

        // BFS经典模板了属于是
        while (!queue.empty())
        {
            // 队列不为空
            if (queue.front())
            {
                // 查看当前是否有符合的节点
                TreeNode *cur = queue.front();
                queue.pop();
                if (set.count(k - cur->val))
                {
                    return true;
                }
                set.insert(cur->val);
                queue.push(cur->left);
                queue.push(cur->right);
            }
            else
            {
                // 空节点需要跳过
                queue.pop();
            }
        }
        return false;
    }
};
// @lc code=end
