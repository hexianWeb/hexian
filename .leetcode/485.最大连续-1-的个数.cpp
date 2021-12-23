#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxCount = 0;
        int count = 0;
        for (int num : nums)
        {
            if (num == 1)
            {
                count++;
            }
            else
            {
                maxCount = max(maxCount, count);
                count = 0;
            }
        }

        return max(maxCount, count);
    }
};
// @lc code=end
