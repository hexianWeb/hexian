#include <string>
#include <stack>
#include <iostream>
// #include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution
{
private:
    // 反转字符串
    void reverse(string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }
    // 去除空格 版本一
    void removeExtraSpaces(string &s)
    {
        // 去除s中间部分的空格
        for (int i = s.size() - 1; i > 0; i--)
        {
            if (s[i] == s[i - 1] && s[i] == ' ')
            {
                s.erase(s.begin() + i);
            }
        }
        // 删除字符串最后面的空格
        if (s.size() > 0 && s[s.size() - 1] == ' ')
        {
            s.erase(s.begin() + s.size() - 1);
        }
        // 删除字符串开头的空格
        if (s.size() > 0 && s[0] == ' ')
        {
            s.erase(s.begin());
        }
    }
    // 去除空格 版本二
public:
    string reverseWords(string s)
    {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);

        for (int i = 0; i < s.size(); i++)
        {
            int j = i;
            while (j < s.size() && s[j] != ' ')
            {
                j++;
            }
            reverse(s, i, j - 1);
            i = j;
        }

        return s;
    }
};
// @lc code=end
