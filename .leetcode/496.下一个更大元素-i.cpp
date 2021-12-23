#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        // 建立nums2的hashmap来存储每个nums2数组中下一个较大数字
        unordered_map<int, int> hashmap;
        // 建立单调栈 递减
        stack<int> stack;

        // 答案数组
        vector<int> res(nums1.size(), 0);

        // 先处理nums2数组
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            // 维护单调递减栈
            while (!stack.empty() && stack.top() <= nums2[i])
            {
                stack.pop();
            }
            hashmap[nums2[i]] = stack.empty() ? -1 : stack.top();
            stack.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            res[i] = hashmap[nums1[i]];
        }

        return res;
    }
};
// @lc code=end
