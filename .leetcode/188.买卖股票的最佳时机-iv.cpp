#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        // 当前的股票总数
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }

        // 创建dp数组 因为题目限制了可以进行k次交易
        // 每次交易都被一次买入一次卖出构成
        // 总共有2k+1次（多余一次代表误操作）
        vector<vector<int>> dp(n, vector<int>(2 * k + 1, 0));

        // 初始化 第0天的操作
        for (int i = 1; i < 2 * k + 1; i += 2)
        {
            dp[0][i] = -prices[0];
        }

        // 递推公式
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 2 * k - 1; j += 2)
            {
                // 第 j 次 持有股票时 可拥有的最大金额
                dp[i][j + 1] = max(dp[i - 1][j] - prices[i], dp[i - 1][j + 1]);
                // 第 j 次 出售股票后 可拥有的最大金额
                dp[i][j + 2] = max(dp[i - 1][j + 1] + prices[i], dp[i - 1][j + 2]);
            }
        }
        return dp[n - 1][2 * k];
    }
};
// @lc code=end
