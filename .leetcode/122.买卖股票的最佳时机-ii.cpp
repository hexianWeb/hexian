#include <vector>
#include <stack>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
// 在跌之前卖掉 单调栈 该出手时就出手
//
// 贪心算法
// 你永远是赚的
// @lc code=start
class Solution
{
public:
    int maxProfit1(vector<int> &prices)
    {
        vector<int> profits;
        stack<int> Stack;
        int money = 0;
        for (int price : prices)
        {
            if (Stack.empty() || price < Stack.top())
            {
                Stack.push(price);
            }
            else if (price > Stack.top())
            {
                money += price - Stack.top();

                Stack.pop();
                Stack.push(price);
            }
        }
        return money;
    }
    int maxProfit(vector<int> &prices)
    {
        int money = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            money += max(0, prices[i] - prices[i - 1]);
        }
        return money;
    }
    int maxProfit3(vector<int> &prices)
    {
        int len = prices.size();
        // 移除脏数据
        if (len == 0)
        {
            return 0;
        }
        vector<vector<int>> dp(len, vector<int>(2));

        // 初始化
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        // 递推公式
        for (int i = 1; i < len; i++)
        {
            // 当前继续持有老的股票 或者直接换购一支新的股票
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            // 当前继续持有已有金额 或者直接卖出手中股票
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[len - 1][1];
    }
};
// @lc code=end
