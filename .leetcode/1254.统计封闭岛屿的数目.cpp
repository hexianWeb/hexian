#include <vector>
#include <queue>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */

// @lc code=start
class Solution
{
private:
    // 矢量数组
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    // 判断岛屿是否合格操作
    bool inArea(vector<vector<int>> &grid, int i, int j)
    {
        return 0 <= i && i < grid.size() && 0 <= j && j < grid[0].size();
    }
    // 刷岛操作函数
    void BFS(vector<vector<int>> &grid, int i, int j, int n, int m)
    {
        // BFS 辅助队列
        queue<pair<int, int>> queue;
        queue.emplace(i, j);

        while (!queue.empty())
        {
            auto elem = queue.front();
            int r = elem.first;
            int c = elem.second;
            queue.pop();
            // 出界判断+刷岛操作
            for (auto dir : dirs)
            {
                int new_r = r + dir[0];
                int new_c = c + dir[1];
                if (inArea(grid, new_r, new_c) && grid[new_r][new_c] == 0)
                {
                    grid[new_r][new_c] = 1;
                    queue.emplace(new_r, new_c);
                }
            }
        }
    }

public:
    int closedIsland(vector<vector<int>> &grid)
    {
        // 答案
        int count = 0;
        // 基本信息
        int n = grid.size();
        int m = grid[0].size();

        // 扫描整张图的边缘 先将边缘的岛屿给刷掉
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                if ((r == 0 || r == n - 1 || c == 0 || c == m - 1) && grid[r][c] == 0)
                {
                    grid[r][c] = 1;
                    BFS(grid, r, c, n, m);
                }
            }
        }

        for (int r = 0; r < n; r++)
        {
            // cout << endl;
            for (int c = 0; c < m; c++)
            {
                // cout << grid[r][c] << " ";
                if (grid[r][c] == 0)
                {
                    count++;
                    grid[r][c] = 1;
                    BFS(grid, r, c, n, m);
                }
            }
        }

        return count;
    }
};
// @lc code=end
