#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
// 解法一 使用Map解决问题
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // 存储答案的数组
        vector<int> ans;
        // 建立一个 key为交集元素 value为元素个数的 map
        unordered_map<int, int> map;
        if (nums1.size() > nums2.size())
        {
            return intersection(nums2, nums1);
        }
        // 建立map
        for (int num : nums1)
        {
            ++map[num];
        }
        for (int num : nums2)
        {
            // count函数用于统计key值在map中出现的次数，
            // map的key不允许重复，因此如果key存在返回1，不存在返回0
            if (map.count(num))
            {
                // 交集中存在这个数
                ans.push_back(num);
                //  减去该元素的个数 因为作为交集已经提取出来
                --map[num];
                if (map)
                {
                    /* code */
                }
                        }
        }
    }
};
// @lc code=end
