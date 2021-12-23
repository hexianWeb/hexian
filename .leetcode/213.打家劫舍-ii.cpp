#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution
{
private:
    // 子串打家劫舍结果
    int robSub(vector<int> &nums, int start, int end)
    {
        if (end == start)
        {
            return nums[end];
        }

        // 动态规划dp数组
        vector<int> dp(nums.size());

        // 初始化
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[end];
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        // 去除脏数组
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return nums[0];
        }
        int res1 = robSub(nums, 0, n - 2);
        int res2 = robSub(nums, 1, n - 1);
        return max(res1, res2);
    }
};
// @lc code=end
