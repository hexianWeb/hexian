#include <vector>
#include <algorithm>
using namespace std;
// 这一题 就是40.组合总和的startIndex限制版本
/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &candidates, int target, int sum, int startIndex, vector<bool> &used)
    {
        //递归终止条件
        if (sum == target)
        {
            result.push_back(path);
            return;
        }

        // 单层逻辑
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
            {
                continue;
            }

            path.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;
            backtracking(candidates, target, sum, i + 1, used);
            path.pop_back();
            used[i] = false;
            sum -= candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        //1.排序是很重要的 对去重起决定因素
        sort(candidates.begin(), candidates.end());
        //建立辅助数组 used 用于去重
        vector<bool> used(candidates.size(), false);
        backtracking(candidates, target, 0, 0, used);
        return result;
    }
};
// @lc code=end
