#include <vector>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // 去除脏数据
        if (nums.size() <= 1)
        {
            return nums.size();
        }

        // 构建dp数组并初始化所有元素最初的最长递增子序列为1
        vector<int> dp(nums.size(), 1);

        // 答案数组
        int ans = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            // 当出现满足递增要求的元素时，获取当前最长的递增子序列
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end
