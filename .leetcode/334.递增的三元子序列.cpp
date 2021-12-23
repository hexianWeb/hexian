#include <vector>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
// 算法思想
// 只需要验证和需要输出不同
//
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int len = nums.size();
        if (len < 3)
            return false;
        int small = 2147483647;
        int mid = 2147483647;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= small)
            {
                small = nums[i];
            }
            else if (nums[i] <= mid)
            {
                mid = nums[i];
            }
            else if (nums[i] > mid)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
/**
 * Trick 就在这里了！假如当前的 small 和 mid 为 [3, 5]，这时又来了个 1。假如我们不将 small 替换为 1，那么，当下一个数字是 2，后面再接上一个 3 的时候，我们就没有办法发现这个 [1,2,3] 的递增数组了！也就是说，我们替换最小值，是为了后续能够更好地更新中间值！

另外，即使我们更新了 small ，这个 small 在 mid 后面，没有严格遵守递增顺序，但它隐含着的真相是，有一个比 small 大比 mid 小的前·最小值出现在 mid 之前。因此，当后续出现比 mid 大的值的时候，我们一样可以通过当前 small 和 mid 推断的确存在着长度为 3 的递增序列。 所以，这样的替换并不会干扰我们后续的计算！

作者：fxxuuu
链接：https://leetcode-cn.com/problems/increasing-triplet-subsequence/solution/c-xian-xing-shi-jian-fu-za-du-xiang-xi-jie-xi-da-b/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
**/