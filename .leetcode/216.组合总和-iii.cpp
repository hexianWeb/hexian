#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
// 算法思想
// 这道题和77的思路很像
// 同样需要找出所有的排序序列 但是有总和为n作为限制条件

// 回溯三步
// 1 .参数 相加之和的目标值 target
//          层数规定        k
//          当前层数数字总和 sum
//          下一层开始的起始for循环遍历位置 startIndex
// 2.终止条件
//          相比77多了一步 target==sum
// 3.单步逻辑
//          相比77多了二步 sum的递归与回溯
class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;

public:
    void backtracking(int target, int k, int sum, int startIndex)
    {
        // 剪枝
        if (sum > target)
        {
            return;
        }

        // 终止条件
        if (path.size() == k)
        {
            if (target == sum)
            {
                result.push_back(path);
            }
            return;
        }
        for (int i = startIndex; i <= 9; i++)
        {
            sum += i;
            path.push_back(i);
            backtracking(target, k, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtracking(n, k, 0, 1);
        return result;
    }
};
// @lc code=end
