#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
// 思想 大饼干满足大孩子 重复这个步骤
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int count = 0;
        while (!s.empty() && !g.empty())
        {
            if (s.back() >= g.back())
            {
                count++;
                s.pop_back();
                g.pop_back();
            }
            else
            {
                g.pop_back();
            }
        }
        return count;
    }
};
// @lc code=end
