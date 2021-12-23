#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int length = digits.size() - 1;
        // 找到第一个不为9的数字+1 后续全部置为0
        for (int i = length; i >= 0; i--)
        {
            if (digits[i] != 9)
            {
                ++digits[i];
                // 后序
                for (int j = i + 1; j < length + 1; j++)
                {
                    digits[j] = 0;
                }
                return digits;
            }
        }
        vector<int> res(length + 2);
        res[0] = 1;
        return res;
    }
};
// @lc code=end
