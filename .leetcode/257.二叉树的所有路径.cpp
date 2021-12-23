#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

// @lc code=start

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 算法思想
// 本题中因为求得路径中处理节点顺序与访问节点顺序一致 所以我们可以选择前序遍历
// 而在要求返回的结果为所以叶子节点的路径
// 则需要用到回溯算法 处理hock的时机就是当遇到了叶子节点

class Solution
{
public:
    // 核心代码 递归+回溯
    // 单层逻辑中 访问节点次序与处理节点次序一致 则 可使用前序遍历
    void BTP(TreeNode *cur, vector<int> &path, vector<string> &res)
    {
        //当前节点入栈
        path.push_back(cur->val);

        // 判断节点是否为 叶子节点 如果是 则将路径记录并且返还
        if (!cur->left && !cur->right)
        {
            // 组合单条结果 并且返回结果集
            int pathSize = path.size();
            string son_path;
            for (int i = 0; i < pathSize - 1; i++)
            {
                // 拼接字符串 此处需要强制类型转换
                son_path += to_string(path[i]);
                son_path += "->";
            }
            son_path += to_string(path[pathSize - 1]);
            res.push_back(son_path);
        }
        // 递归 回溯 成双成对
        if (cur->left)
        {
            // 递归
            BTP(cur->left, path, res);
            // 回溯
            path.pop_back();
        }
        if (cur->right)
        {
            BTP(cur->right, path, res);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        // 建立结果集合
        vector<string> res;
        // 建立路程存储集合 (后序需要使用to_string强制类型转换)
        vector<int> path;

        if (!root)
        {
            return res;
        }

        BTP(root, path, res);
        return res;
    }
};
// @lc code=end
