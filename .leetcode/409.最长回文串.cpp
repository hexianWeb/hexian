#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution
{
public:
    int longestPalindrome(string s)
    {
        sort(s.begin(), s.end());
        // 建立辅助栈
        stack<char> stack;
        // 计数器count
        int count = 0;
        // 载入元素
        stack.push(s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            if (!stack.empty() && s[i] == stack.top())
            {
                stack.pop();
                count += 2;
                continue;
            }
            stack.push(s[i]);
        }
        if (!stack.empty())
        {
            count++;
        }
        return count;
    }
};
// @lc code=end
