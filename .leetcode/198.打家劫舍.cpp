#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int length = nums.size();
        if (length == 0)
        {
            return 0;
        }
        if (length == 1)
        {
            return nums[0];
        }

        vector<int> money(length);

        // 初始化
        money[0] = nums[0];
        money[1] = max(nums[0], nums[1]);

        // 确定便利顺序 2-》n
        for (int i = 2; i < length; i++)
        {
            money[i] = max(money[i - 1], money[i - 2] + nums[i]);
        }
        return max(money[length - 1], money[length - 2]);
    }
};
// @lc code=end
