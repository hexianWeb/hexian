#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
// 赎金信
// 本题中 作为key键的字母仅有26个数字组成
//
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int s[26] = {0};
        // 记录下所有字母出现的次数
        for (auto i : magazine)
        {
            s[i - 'a']++;
        }
        for (auto i : ransomNote)
        {
            if (s[i - 'a']--)
            {
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
