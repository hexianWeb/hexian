#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
// 算法思想
//  常数级空间排序 堆排序
// 荷兰国旗
// 只有三种颜色 0 1 2
// 为每一种颜色分配一个区域
// 把最中间的颜色1视为target
// 则分成的三个区域为：
//  分别是 num<target => less区域
//        num== target =>target区域
//        num>target =>more区域
// 遍历数组中的元素（颜色）
// 当此时的值小于target
// 则当前值与less区域的边界交换
// 然后扩展less区域，将目标值纳入less区域中
// 若当前值大于target
// 则当前值与more区域的边界交换
// 然后扩展more区域，将目标值纳入more区域
// 等于target
// 不做任何调换操作 continue；
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int less = -1;
        int more = nums.size();
        int target = 1;
        for (int i = 0; i < nums.size();)
        {
            // 颜色已经分类完毕
            if (i == more)
            {
                return;
            }
            if (nums[i] < target)
            {
                swap(nums[i], nums[less + 1]);
                less++;
                i++;
            }
            else if (nums[i] > target)
            {
                // 这里我们不知道换过来的less区域前一个元素是什么情况 i原地不动
                swap(nums[i], nums[more - 1]);
                more--;
            }
            else if (nums[i] == target)
            {
                i++;
            }
        }
    }
};
// @lc code=end
