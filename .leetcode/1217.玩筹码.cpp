#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1217 lang=cpp
 *
 * [1217] 玩筹码
 */

// @lc code=start
class Solution
{
    // 由题目可知 筹码移动两位无需代价
    // 则优先选择无代价将筹码尽可能的移动到一起
    // 这样就可以形成两堆筹码 一堆奇数 一堆偶数
    // 接下来奇数移动到偶数 不可避免的要消耗一个代价 则选取两者中的最小值
public:
    int minCostToMoveChips(vector<int> &position)
    {
        // 奇数
        int odd = 0;
        // 偶数
        int even = 0;
        for (int num : position)
        {
            if ((num & 1) == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        return min(odd, even);
    }
};
// @lc code=end
