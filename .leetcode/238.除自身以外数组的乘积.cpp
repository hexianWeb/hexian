#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int length = nums.size();
        vector<int> L(length, 0);
        vector<int> R(length, 0);
        vector<int> res(length);
        L[0] = 1;
        R[length - 1] = 1;
        // 构建左缀乘积数组
        for (int i = 1; i < length; i++)
        {
            L[i] = nums[i - 1] * L[i - 1];
        }
        // 构建右缀
        for (int i = length - 1; i > 0; i--)
        {
            R[i - 1] = R[i] * nums[i];
            cout << R[i] << endl;
        }

        for (int i = 0; i < length; i++)
        {
            res[i] = L[i] * R[i];
        }
        return res;
    }
};
// @lc code=end
