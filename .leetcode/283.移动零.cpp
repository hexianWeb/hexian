#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
        {
            if (nums[fastIndex] != 0)
            {
                // nums[slowIndex++] = nums[fastIndex];
                swap(nums[slowIndex++], nums[fastIndex]);
            }
        }
    }
};
// @lc code=end
