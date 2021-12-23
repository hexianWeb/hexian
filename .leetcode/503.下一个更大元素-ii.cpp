#include <vector>
#include <stack>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {

        vector<int> nums_double(nums.size() * 2, 0);

        vector<int> res(nums.size() * 2, 0);

        // 建立单调栈
        stack<int> stack;
        // 再加一个一模一样的数组在后面
        for (int i = 0; i < nums.size(); i++)
        {
            nums_double[i] = nums[i];
            nums_double[i + nums.size()] = nums[i];
        }
        // 熟悉的配方 熟悉的味道 上一题一样的单调栈
        for (int i = nums_double.size() - 1; i >= 0; i--)
        {
            while (!stack.empty() && stack.top() <= nums_double[i])
            {
                stack.pop();
            }
            res[i] = stack.empty() ? -1 : stack.top();
            stack.push(nums_double[i]);
        }
        vector<int> ans{&res[0], &res[0] + nums.size()};

        return ans;
    }
};
// @lc code=end
