/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
// 这题使用递归会超出时间限制 所以不能用递归
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1 || n == 2)
        {
            return n;
        }
        int i1 = 1;
        int i2 = 2;
        for (int i = 3; i <= n; i++)
        {
            int next = i1 + i2;
            i1 = i2;
            i2 = next;
        }
        return i2;
    }
};
// @lc code=end
