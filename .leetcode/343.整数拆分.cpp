#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i - 1; j++)
            {
                cout << dp[i] << " " << j * (i - j) << " " << j * dp[i - j] << endl;
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
                // dp[i] = max(dp[i - j] * j, (i - j) * j);
            }
        }
        return dp[n];
    }
};
// @lc code=end
