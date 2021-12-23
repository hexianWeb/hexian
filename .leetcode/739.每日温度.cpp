#include <vector>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {

        // 建立答案数组
        vector<int> res(temperatures.size(), 0);
        // 建立辅助单调栈
        stack<int> Stack;

        // 遍历当前每日气温
        for (int i = 0; i < temperatures.size(); i++)
        {
            // 若当前的数组不为空且单调栈被破坏
            while (
                !Stack.empty() && temperatures[i] > temperatures[Stack.top()])
            {
                int num = Stack.top();
                Stack.pop();
                res[num] = (i - num);
            }

            Stack.push(i);
        }
        return res;
    }
};
// @lc code=end
