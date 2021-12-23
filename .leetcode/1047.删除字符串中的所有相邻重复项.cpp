#include <stack>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution
{
public:
    string reverse_String(string &s)
    {
        int num = s.size();
        for (int i = 0, j = num - 1; i < j; i++, j--)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        return s;
    }
    string removeDuplicates(string s)
    {
        // 建立辅助栈
        stack<char> Stack;
        for (char cur : s)
        {
            // 除第一个元素外 后序的元素与栈顶相同则去除该元素
            if (Stack.empty() || cur != Stack.top())
            {
                Stack.push(cur);
            }
            else
            {
                Stack.pop();
            }
        }
        // 建立答案数组
        string ans = "";
        int num = Stack.size();
        // 栈中元素直接输出与需要的答案相反 需要反转
        for (int i = 0; i < num; i++)
        {
            char temp = Stack.top();
            Stack.pop();
            ans += temp;
        }
        reverse(ans.begin(), ans.end());
        // reverse_String(ans);
        return ans;
    }
};
// @lc code=end
