#include <algorithm>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=1247 lang=cpp
 *
 * [1247] 交换字符使得字符串相同
 */

// @lc code=start
class Solution
{
public:
    // 除去相同元素 则剩下的元素为匹配比对不成功的
    // 那么无外乎三种情况 两大类
    // 类一
    // s1: XX s2: YY
    // s1与s2 要相同需要交换一次
    // 同等情况还有
    // S1：YY S2：XX
    // 类二
    // S1 :XY S2 ：YX
    // 则需要交换两次
    // 交换次数这应该为
    // XX ,YY 的对数 + XY的个数
    int minimumSwap(string s1, string s2)
    {
        string s;

        int count_X = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                s.push_back(s1[i]);
                if (s1[i] == 'x')
                {
                    count_X++;
                }
            }
        }
        int count_Y = s.size() - count_X;
        if ((count_X + count_Y) % 2 != 0)
        {
            return -1;
        }
        return count_X / 2 + count_Y / 2 + (count_X % 2) * 2;
    }
};
// @lc code=end
