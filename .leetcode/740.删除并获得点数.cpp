#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */

// @lc code=start
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int n = nums.size();
        // 去除脏数据
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return nums[0];
        }

        // 先对目标数组进行排序
        sort(nums.begin(), nums.end());
        // 最大数
        int maxNum = nums[n - 1];
        // 建立“房子”数组 house 因为有0的存在 除了 1~最大数 还有 0
        vector<int> house(maxNum + 1, 0);
        // 初始化房子数组
        for (int num : nums)
        {
            house[num]++;
        }

        // 建立动态规划数组dp
        vector<int> dp((maxNum + 1), 0);

        // 初始化
        dp[1] = house[1];

        for (int i = 2; i <= maxNum; i++)
        {
            dp[i] = max(dp[i - 1], house[i] * i + dp[i - 2]);
        }
        return dp[maxNum];
    }
};
// @lc code=end
