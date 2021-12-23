#include <vector>
#include <queue>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 */

// @lc code=start
class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        // BFS存储即将处理的节点
        queue<vector<int>> queue;
        // 扫描图必备长宽
        int n = grid.size();
        int m = grid[0].size();

        // 获取所有陆地节点
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                if (grid[r][c] == 1)
                {
                    queue.push({r, c});
                }
            }
        }
        // 全是陆地 或者 全是海洋
        if (queue.size() == n * m || queue.empty())
        {
            return -1;
        }
        // 结果坐标记录 一定是最后一个 越到后面距离越大
        vector<int> res;
        while (!queue.empty())
        {
            res = queue.front();
            // 获取当前坐标
            int i = queue.front()[0];
            int j = queue.front()[1];
            // cout << grid[res[0]][res[1]] << endl;
            queue.pop();
            // 刷岛操作+出界判断
            // 向上移动
            if (i > 0 && grid[i - 1][j] == 0)
            {
                grid[i - 1][j] = grid[i][j] + 1;
                queue.push({i - 1, j});
            }
            // 向下移动
            if (i < n - 1 && grid[i + 1][j] == 0)
            {
                grid[i + 1][j] = grid[i][j] + 1;
                queue.push({i + 1, j});
            }
            // 向左移动
            if (j > 0 && grid[i][j - 1] == 0)
            {
                grid[i][j - 1] = grid[i][j] + 1;
                queue.push({i, j - 1});
            }
            // 向右移动
            if (j < m - 1 && grid[i][j + 1] == 0)
            {
                grid[i][j + 1] = grid[i][j] + 1;
                queue.push({i, j + 1});
            }
        }

        return grid[res[0]][res[1]] - 1;
    }
};
// @lc code=end
