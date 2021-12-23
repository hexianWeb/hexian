#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        // 双指针算法
        // int length = s.size();

        // for (int i = 0, j = length - 1; i <= j; i++, j--)
        // {
        //     char tmp = s[i];
        //     s[i] = s[j];
        //     s[j] = tmp;
        // }

        // 嘿嘿
        reverse(s.begin(), s.end());
    }
};
// @lc code=end
