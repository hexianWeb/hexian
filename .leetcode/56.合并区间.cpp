#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // 去除脏数据 无序排序
        if (intervals.size() == 0)
        {
            return {};
        }
        // 将数组排序
        sort(intervals.begin(), intervals.end());

        // 答案数组
        vector<vector<int>> merged;

        // 初始化操作
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            // 左边界设置
            int left = intervals[i][0];
            // 右边界设置
            int right = intervals[i][1];
            // 当前遍历的区间左边界在 已经融合区域右边界左侧 说明右重叠部分 需要合并
            if (left <= merged.back()[1])
            {
                // 直接改写数组 取两者的最大值
                merged.back()[1] = max(merged.back()[1], right);
            }
            else
            {
                merged.push_back({left, right});
            }
        }

        // 返回答案数组
        return merged;
    }
};
// @lc code=end
