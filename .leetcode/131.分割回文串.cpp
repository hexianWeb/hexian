#include <vector>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution
{
private:
    vector<vector<string>> res;
    vector<string> path;
    bool isPalindrome(string &s, int begin, int end)
    {
        for (int i = begin, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }
    void backtracking(int startIndex, string &s)
    {
        // 终止条件
        if (startIndex >= s.size())
        {
            res.push_back(path);
            return;
        }

        // 单层逻辑
        for (int i = startIndex; i < s.size(); i++)
        {
            if (isPalindrome(s, startIndex, i))
            {
                path.push_back(s.substr(startIndex, i - startIndex + 1));
            }
            else
            {
                continue;
            }
            backtracking(i + 1, s);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        backtracking(0, s);
        return res;
    }
};
// @lc code=end
