#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        // 去除脏数据
        if (nums.size() <= 1)
        {
            return n;
        }

        // 初始化dp数组以及count数组
        vector<int> dp(n, 1);
        vector<int> count(n, 1);

        //最长子序列长度
        int maxLength = 0;
        // 答案数组
        int res = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    // 当前最长的递增子序列长度要被更新
                    if (dp[j] + 1 > dp[i])
                    {
                        count[i] = count[j];
                        dp[i] = dp[j] + 1;
                    }
                    // 当前最长子序列长度不会被更新 但是 可以有其余方式组成当前最长子字符串
                    else if (dp[j] + 1 == dp[i])
                    {
                        count[i] += count[j];
                    }
                }
            }
            if (dp[i] > maxLength)
            {
                maxLength = dp[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxLength)
            {
                res += count[i];
            }
        }

        return res;
    }
};
// @lc code=end
