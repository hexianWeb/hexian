#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // 区间 []
        int left = 0;
        int right = nums.size() - 1;

        // 在左闭右闭区间内 left == right仍然有效
        while (left <= right)
        {
            int mid = left + (right - left) / 2; // 防止溢出

            if (nums[mid] > target)
            {
                right = mid - 1; // target 一定不再 [mid,right] 区间内
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};
// @lc code=end
