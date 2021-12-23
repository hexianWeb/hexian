#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
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
    int numTrees(int n)
    {
        // 建立辅助数组
        // 其中dp[i]代表的是当前有i个节点的情况下 二叉搜索树有多少种
        vector<int> dp(n + 1, 0);
        // 去除脏数据
        if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }
        // 初始化
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            // 头结点为 j时 依照二叉搜索树的性质 左边节点有 j-1个 右边节点数有 i-j个
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
// @lc code=end
