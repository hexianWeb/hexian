#include <string>
#include <iostream>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution
{
private:
    // 数组字符辅助栈
    stack<int> nums;
    // op字符辅助栈
    stack<string> op;

public:
    string decodeString(string s)
    {
        string res = "";
        int num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // 处理数字
            if (s[i] >= '0' && s[i] <= '9')
            {
                // 配合隐式转换
                num = num * 10 + s[i] - '0';
                // 处理字符
                else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                {
                    res += s[i];
                }
                else if (s[i] == '[')
                {
                    nums.push(num);
                    op.push(res);
                    // 重置num
                    num = 0;
                    res = "";
                }
                else
                {
                    int n = nums.top();
                    nums.pop();
                    for (int i = 0; i < n; i++)
                    {
                        op.top() += res;
                    }
                    res = op.top();
                    op.pop();
                }
                // 开始进入数字栈
            }
            return res;
        }
    };
    // @lc code=end
