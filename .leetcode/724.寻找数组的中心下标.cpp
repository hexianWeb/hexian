#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        // 数组总价值
        int total = 0;
        // 左侧总和
        int sum = 0;
        for (auto num : nums)
        {
            total += num;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (2 * sum + nums[i] == total)
            {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};
// @lc code=end
