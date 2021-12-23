#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
// 依据题意
// 除了其中一个元素以外 其余都出现两次
// 而异或运算中有
// 1^0=1
// 1^1=0
// 则每两个相同元素异或就会抵消 最后只剩下单独出现一次的元素^0
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            nums[0] ^= nums[i];
        }

        return nums[0];
    }
};
// @lc code=end
