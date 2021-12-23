#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1029 lang=cpp
 *
 * [1029] 两地调度
 */

// @lc code=start
// 返回true就是第一个数排在前面

// 返回false就是第一个数排在后面
class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        // 比较器 按照aCost -bCost的差值 从小到大排序
        sort(costs.begin(), costs.end(), [](const vector<int> &o1, const vector<int> &o2)
             { return (o1[0] - o1[1]) < (o2[0] - o2[1]); });
        int total = 0;
        int n = costs.size() / 2;
        for (int i = 0; i < n; i++)
        {
            total += costs[i][0] + costs[i + n][1];
        }
        return total;
    }
};
// Thinking:
// 先假设所以用户都要去B地出差
// 此时价格为priceB的总和
// 如果这个时候将一半人临时改为A地
// 则当前价格为 sum=sum原来-PriceB改+PriceA改
// 故要PriceA改-PriceB改 最小的一群人前往B地才行
// @lc code=end
