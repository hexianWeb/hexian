#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0)
        {
            // 隐式转换
            int x = i >= 0 ? a[i] - '0' : 0;
            int y = j >= 0 ? b[j] - '0' : 0;
            int sum = x ^ y ^ carry;
            if (x + y + carry >= 2)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            res.push_back('0' + sum);
            i--;
            j--;
        }
        if (carry)
        {
            res.push_back('0' + carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
