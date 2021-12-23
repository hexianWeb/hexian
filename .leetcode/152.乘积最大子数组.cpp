#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        else if (nums.size() == 1)
        {
            return nums[0];
        }
        int MaxNum = nums[0];
        int MinNum = nums[0];

        // 答案
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int temp = MaxNum;
            MaxNum = max(nums[i], max(nums[i] * MaxNum, nums[i] * MinNum));
            MinNum = min(nums[i], min(nums[i] * temp, nums[i] * MinNum));
            cout << MaxNum << " " << MinNum << endl;
            if (MaxNum > res)
            {
                res = MaxNum;
            }
        }
        return res;
    }
};
// @lc code=end
