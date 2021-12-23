#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */

// @lc code=start
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int ans = 0;
        queue<char> queue;
        if (s.size() == 0)
        {
            return 0;
        }
        for (auto s_char : s)
        {
            switch (s_char)
            {
            case '(':
                queue.push(s_char);
                break;
            case ')':
                if (queue.empty())
                {
                    ans += 1;
                }
                else
                {
                    queue.pop();
                }

            default:
                break;
            }
        }
        return queue.empty() ? ans : (ans + queue.size());
    }
};

// @lc code=end
