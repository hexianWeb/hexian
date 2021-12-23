#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 获取数组长度
        int n = prices.size();
        // 创建动态dp数组
        // 有5种状态 分别是 0:误操作 1：第一次买入 2：第一次卖出 3： 4： 等
        vector<vector<int>> dp(n, vector<int>(5, 0));

        // 初始化dp[0][i]
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];

        // 递推公式
        for (int i = 1; i < n; i++)
        {
            // 第一次持有股票 选择持有当前股票 ，或者不持有
            dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
            // 第一次出售股票(可能) 选择在当前出售股票 或者继续持有
            dp[i][2] = max(dp[i - 1][1] + prices[i], dp[i - 1][2]);
            // 第二次持有
            dp[i][3] = max(dp[i - 1][2] - prices[i], dp[i - 1][3]);
            // 第二次出售
            dp[i][4] = max(dp[i - 1][3] + prices[i], dp[i - 1][4]);
        }
        return dp[n - 1][4];
    }
};
// @lc code=end
