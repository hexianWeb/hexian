#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        // 去除脏数据
        if (nums.size() <= 1)
        {
            return nums.size();
        }
        // 答案
        int ans = 0;
        // 创建dp数组 初始化每个元素的最长连续递增序列为1
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i] = max(dp[i], dp[i - 1] + 1);
            }
            if (dp[i] > ans)
            {
                ans = dp[i];
            }
        }
        return ans;
    }
};
// @lc code=end
