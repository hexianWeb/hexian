#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string num;
        int l1 = num1.size() - 1;
        int l2 = num2.size() - 1;
        // 是否进位
        int carry = 0;
        while (l1 >= 0 || l2 >= 0)
        {
            // 隐式转换
            int x = l1 >= 0 ? num1[l1] - '0' : 0;
            int y = l2 >= 0 ? num2[l2] - '0' : 0;

            int sum = x + y + carry;
            if (sum >= 10)
            {
                sum = sum % 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            num.push_back('0' + sum);
            l1--;
            l2--;
        }
        if (carry)
        {
            num.push_back('0' + carry);
        }
        reverse(num.begin(), num.end());
        return num;
    }
};
// @lc code=end
