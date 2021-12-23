#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
// 算法思想
// 若三个数 a+b+c=0
// 则必须有其中一个数小于0，一个数大于0
// 若nums中所有的数组都小于或者大于0 则不存在
// 随后遍历数组时我规定
// a=nums[i] b=nums[left] c=nums[right] （left =i+1 right=nums.end()）
// 每循环一个数字i时 都开始移动left right 指针 试图找到 a+b+c=0；
// left right 移动过程中a+b+c<0 则 left++ 使整体结果变大
// 反之你懂得
// 最后 因为不允许出现重复三元组
// 找到答案后 left 看 右边的值 right 看左边的值 是否和自己一样 一样则跳过

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            // 他已经不可能构成三元组了
            if (nums[i] > 0)
            {
                return res;
            }
            // a数 去重
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            // 双指针移动 寻找合适的值
            while (left < right)
            {
                if (nums[left] + nums[right] + nums[i] < 0)
                {
                    left++;
                }
                else if (nums[left] + nums[right] + nums[i] > 0)
                {
                    right--;
                }
                else
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    // b数去重
                    while (right > left && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    // c数去重
                    while (right > left && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
