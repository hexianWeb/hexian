#include <string>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            // 每隔2k的字符就反转前面k个字符
            if (i + k <= s.size())
            {
                reverse(s.begin() + i, s.begin() + i + k);
                continue;
            }
            // 数量不够了 全部反转
            reverse(s.begin() + i, s.end());
        }
        return s;
    }
};
// @lc code=end
