#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // 快慢指针初始化
        int fast = 0;
        int slow = 0;

        int sum = 0;
        // 答案
        int res = nums.size() + 1;

        for (; fast < nums.size(); ++fast)
        {
            sum += nums[fast];
            if (sum >= target)
            {
                while (1)
                {
                    if (sum - nums[slow] >= target)
                    {
                        sum -= nums[slow++];
                    }
                    else
                    {
                        break;
                    }
                }
                if (fast - slow + 1 < res)
                {
                    res = fast - slow + 1;
                }
            }
        }
        if (res < nums.size() + 1)
        {
            return res;
        }
        else
        {
            return 0;
        }
    }
};
// @lc code=end
