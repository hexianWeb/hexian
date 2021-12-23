#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
// 这道题和合并区间十分类似 都存在一个判断区间是否重复的判断
// 这里沿用当时的操作
// 将0的右侧设为初始右侧基准
// 从1开始向后遍历 如果有区间的左边界小于右侧基准 这时就说明 区间存在重叠
// 那么就要开始处理重叠的区间了
// 这里处理方式是 右侧区间小的留下 因为这样能够去重更少的区间
// 例如 【1，2】 【1，3】【2，3】
// 如果我们选择去除【1，2】 留给右侧的空间更少 更容易发生重叠
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        // 将获取的数组按头元素从小到大排序
        sort(intervals.begin(), intervals.end());
        int count = 0;
        // 右侧基准线
        int Pre_R = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            int L = intervals[i][0];
            int R = intervals[i][1];
            // 区间发生重复
            if (L < Pre_R)
            {
                count++;
                // 跟新右侧基准线 留下靠左的
                Pre_R = min(Pre_R, R);
            }
            else
            {
                // 更新右侧基准线
                Pre_R = R;
            }
        }
        return count;
    }
};
// @lc code=end
