#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
// 为 题77与216的结合 少了下层for循环开始遍历时的起始位置
//                  多了对当前是否还有必要继续循环下去的剪枝操作
// 回溯三步 直接写代码了
// @lc code=start
class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int> &candidates, int target, int sum, int startIndex)
    {
        // 先上剪枝操作 减少不必要的运算
        if (sum > target)
        {
            return;
        }
        // 终止条件
        if (sum == target)
        {
            // 结果成立 拉入结果集
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size(); i++)
        {
            // 子问题发展趋势不缩小 startIndex不变
            startIndex = i;
            // 递归
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, startIndex);
            // 回溯
            path.pop_back();
            sum -= candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backtracking(candidates, target, 0, 0);
        return result;
    }
};
// @lc code=end
