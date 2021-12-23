#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
// 方法一
// 建立一个辅助数组来存储二叉树从根节点到叶子节点的路径
// 当到达叶子节点的时候 将path中的数字组合为结果后返回
// 缺点：空间开销 构建了一个额外的数组
// 方法二
// 深度优先搜索
// 从根节点开始，遍历每个节点
// 如果遇到叶子节点 则将叶子节点对应的数字返还到数字之和
// 如果不是叶子节点 则计算其子节点对应的数字
// 然后对子节点进行遍历
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
    // 方法一
    // void binaryTreePath(TreeNode *cur, vector<int> &path, int &res)
    // {
    //     path.push_back(cur->val);

    //     // 判断当前是否是根节点 如果是 则该条路径可以被计算
    //     if (!cur->left && !cur->right)
    //     {
    //         int pathSize = path.size();
    //         int son_res = 0;
    //         for (int i = 0; i < path.size(); i++)
    //         {
    //             son_res += path[i] * pow(10, pathSize - 1 - i);
    //             cout << son_res << " " << endl;
    //         }
    //         res += son_res;
    //     }

    //     // 递归回溯
    //     if (cur->left)
    //     {
    //         binaryTreePath(cur->left, path, res);
    //         path.pop_back();
    //     }
    //     if (cur->right)
    //     {
    //         binaryTreePath(cur->right, path, res);
    //         path.pop_back();
    //     }
    // };
    int dfs(TreeNode *root, int prevSum)
    {
        if (!root)
        {
            return 0;
        }
        int num = root->val + prevSum * 10;

        if (!root->left && !root->right)
        {
            return num;
        }
        else
        {
            return dfs(root->left, num) + dfs(root->right, num);
        }
    }
    // 方法二
    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }
};
// @lc code=end
