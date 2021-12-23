#include <vector>
#include <iostream>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
private:
    vector<string> res;
    string path;
    // 数字与字母的映射
    const string lettetMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"

    };

public:
    // 回溯算法
    // 其中 index为遍历到那一个 digits的数字
    void backtracking(string digits, int index)
    {
        // 终止条件
        if (index == digits.size())
        {
            res.push_back(path);
            return;
        }
        // 单层逻辑
        // 获取当前数字所对应的字母映射合集
        int num = digits[index] - '0';
        string collection = lettetMap[num];
        for (int i = 0; i < collection.size(); i++)
        {
            path.push_back(collection[i]);
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return res;
        }

        backtracking(digits, 0);
        return res;
    }
};
// @lc code=end
