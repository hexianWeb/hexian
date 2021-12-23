#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution
{
private:
    // 总条数 count
    int count = 0;
    // 递归参数
    // 当前数组下标 处理数组对象 当前目标值 当前累计值
    void dfs(int index, vector<int> &nums, int target, int sum)
    {
        // 终止条件
        if (index == nums.size())
        {
            if (sum == target)
            {
                count++;
            }
            return;
        }
        // 数组下标加1
        dfs(index + 1, nums, target, sum + nums[index]);
        dfs(index + 1, nums, target, sum - nums[index]);
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        dfs(0, nums, target, 0);
        return count;
    }
};
// @lc code=end
