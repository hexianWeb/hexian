#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 数组形式的整数加法
 */

// @lc code=start
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        // 建立辅助数组
        vector<int> res;
        int i = num.size() - 1;
        int carry = 0;
        while (i >= 0 || k != 0)
        {
            int x = i >= 0 ? num[i] : 0;
            int y = k != 0 ? k % 10 : 0;
            int sum = x + y + carry;
            if (sum >= 10)
            {
                sum = sum % 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            res.push_back(sum);
            i--;
            k = k / 10;
        }
        if (carry)
        {
            res.push_back(carry);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
