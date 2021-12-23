#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
// 换个角度看 世界不一样
// up down 相对而言 up 由down产生 down 由up产生
class Solution
{
private:
    int Max_count = -1;

public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int up = 1;
        int down = 1;
        if (nums.size() < 2)
        {
            return nums.size();
        }

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] > 0)
            {
                up = down + 1;
            }
            if (nums[i] - nums[i - 1] < 0)
            {
                down = up + 1;
            }
        }
        return max(up, down);
    }
};
// @lc code=end
