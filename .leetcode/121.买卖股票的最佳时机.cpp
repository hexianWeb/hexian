#include <stack>
#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
// 单次出售股票 无需动态规划
// 算法思想 假设每天都在卖股票
//  在第i天卖股票 要想获取利润最高需要在 前i-1天中 最低价购买股票在这天卖出
// 然后得到的利润和前i-1天对比 最大利润留下
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int inf = 10000000000000;
        int minPrice = inf;
        int maxprofit = 0;
        for (int price : prices)
        {
            maxprofit = max(maxprofit, price - minPrice);
            minPrice = min(price, minPrice);
        }
        return maxprofit;
    }
};
// @lc code=end
