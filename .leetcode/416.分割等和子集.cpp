#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        vector<int> dp(10001, 0);

        // 求出当前集合的总和
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 == 1)
            return false;
        // 求出子集合目标值
        int target = sum / 2;

        // 先遍历物品数量
        for (int i = 0; i < nums.size(); i++)
        {
            // 后遍历“背包”容量 一维数组 倒叙遍历
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
