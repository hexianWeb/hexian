#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
// 投票算法
// 算法思想
// 当前国家有领导人选举大会
// 国际内部各党开始竞票
// 当有一党出现要当领导人的趋势时，其余党就开始投反对票
// 直到投票结束 优势党则为多数元素
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = -1;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (candidate == nums[i])
            {
                // 同党投赞成票
                count++;
            }
            // 其余党投反对票
            else
            {
                count--;
            }
            // 优势不在 领导者转换
            if (count < 0)
            {
                candidate = nums[i];
                count++;
            }
        }

        // 投票结束 当前candidate当领导人
        return candidate;
    }
};
// @lc code=end
