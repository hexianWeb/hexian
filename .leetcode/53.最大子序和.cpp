#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
// 最大子序和
// 贪心解法算法思想
// 如果想要子序和最大，则子序和的前缀必须对子序和的增加有益，这样我们才有保留它的理由
// 比如说 选择 -2，1，X,X,X，Y
// 这时-2，1总和为-1，加后面的为3X-1，那我为什么不选3X做新的子序呢？
// 所以 最大子序和前缀必须对本身有益
class Solution
{
public:
    int maxSubArray_02(vector<int> &nums)
    {
        int ans = -2147483648;
        int sum = 0;
        for (int num : nums)
        {
            if (sum > 0)
            {
                // 可以保留  并且向后看看
                sum += num;
            }
            else
            {
                sum = num;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
    int maxSubArray(vector<int> &nums)
    {
        // 排除脏数据情况
        if (nums.size() == 0)
        {
            return 0;
        }
        // 构建dp数组
        vector<int> dp(nums.size(), 0);

        // 初始化
        dp[0] = nums[0];
        int res = dp[0];

        for (int i = 1; i < nums.size(); i++)
        {
            // 递推公式
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (res < dp[i])
            {
                res = dp[i];
            }
        }
        return res;
    }
};
// @lc code=end
