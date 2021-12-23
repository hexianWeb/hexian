#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
// 动态规划思想
// 1.确定DP数组下标的含义
// 我选择定义一个SUM数组
// SUM【n】表示上到第N层台阶需要花费的总体力
// 2.递推公式
// 上到第N层要花费的最小体力
// 处除了第N层台阶本身一定要花费的体力外
// 我们还需要能到达N层台阶的方式途径
// 即为min（sum【n-1】,sum[n-2]）
// sum(n)=min(sum(n-1),sum(n-2))+cost(n);
// 3.初始化
// 在题目中已经明示
// sum[0]=cost[0]
// sum[1]=cost[1]
// 4.确定遍历顺序 即为从3到n
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int length = cost.size();
        vector<int> sum(length);
        sum[0] = cost[0];
        sum[1] = cost[1];
        for (int i = 2; i < length; i++)
        {
            sum[i] = min(sum[i - 1], sum[i - 2]) + cost[i];
        }
        return min(sum[length - 1], sum[length - 2]);
    }
};
// @lc code=end
