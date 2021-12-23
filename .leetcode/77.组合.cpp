#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;

    // 回溯三步
    // 1. 递归函数的参数 以及返回值
    void backtracking(int n, int k, int startIndex)
    {
        // 2.终止条件
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }
        // 3.单层逻辑
        // 剪枝操作
        // 如果当前循环剩下的元素已经不足我们需要的元素个数 则可以直接放弃
        // 例如 n=4 k=4
        // path.size 当前选择了的元素个数
        //  k 所需元素个数
        //  n 元素总数
        // for不用遍历
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++)
        {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        backtracking(n, k, 1);
        return result;
    }
};
// @lc code=end
