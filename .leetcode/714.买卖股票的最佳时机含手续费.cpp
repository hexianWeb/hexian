#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution
{
public:
    // 方法一 贪心算法
    int maxProfit2(vector<int> &prices, int fee)
    {
        // 答案数
        int res = 0;
        // 设立最小数
        int min_Num = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            // 盈利
            int profit = prices[i] - min_Num - fee;
            // CASE1 设定我们在min_Num处购进股票
            if (prices[i] < min_Num)
            {
                min_Num = prices[i];
            }
            // CASE2 有盈利区间 但 赚的金额小于手续费
            if (prices[i] >= min_Num && profit <= 0)
            {
                // 不盈利 continue
                continue;
            }
            // CASE3
            if (profit > 0)
            {
                // 盈利 但不一定最优
                res += profit;
                // 避免重复减去手续费
                min_Num = prices[i] - fee;
            }
        }
        return res;
    }

    // 二 动态递归法
    //  延续122解题思路 将手续费添加至购买成本即可
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(2, 0));

        // 初始化
        dp[0][0] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][0] + prices[i] - fee, dp[i - 1][1]);
        }
        return dp[n - 1][1];
    }
};
// @lc code=end
