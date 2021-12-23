#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
// 算法思想
// 初始化一个key值有26个的数组字母哈希表
// 遍历s 与 t字符 其中 s字符串负责++ t字符串负责--
// 最后check当前数组中所有的value都为0则返回 true 否则为false
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // 先判断两者长度是否匹配
        if (s.length() != t.length())
        {
            return false;
        }
        // 哈希表
        int map[26] = {0};

        for (int i = 0; i < s.length(); i++)
        {
            map[s[i] - 'a']++;
            map[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (map[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
