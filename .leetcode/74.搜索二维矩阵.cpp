#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution
{
public:
    //一暴力递归法
    // 开暴 我摆了 说白了 我是傻逼 草
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int width = 0;
        int height = matrix[0].size() - 1;

        while (width < matrix.size() && height >= 0)
        {
            if (matrix[width][height] < target)
            {
                width++;
            }
            else if (matrix[width][height] > target)
            {
                height--;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end
