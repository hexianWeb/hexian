#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1710 lang=cpp
 *
 * [1710] 卡车上的最大单元数
 */

// @lc code=start
class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        // 自定义从小到大的比较器
        sort(boxTypes.begin(), boxTypes.end(), [](const auto &L, const auto &R)
             { return L[1] > R[1]; });
        int ans = 0, num = 0;
        // 若当前卡车还有空间且还有货物 则放入单元数最多的货物
        for (int i = 0; i < boxTypes.size() && truckSize > 0; i++)
        {
            // 装或数量受还剩多少货物以及卡车容量限制
            num = min(truckSize, boxTypes[i][0]);
            truckSize -= num;
            ans += boxTypes[i][1] * num;
        }
        return ans;
    }
};
// @lc code=end
