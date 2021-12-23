#include <vector>
#include <queue>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
// 如果说DFS是不撞南墙不回头的探索方法
// BFS的探索方法更像是一盆倒在地上会四处扩散的水
class Solution
{

private:
    int island = 0;
    // 深度遍历岛屿周围的节点 将同一个岛屿刷掉以此来避免经历重复的节点
    void DFS(vector<vector<char>> &grid, int r, int c)
    {

        int nr = grid.size();
        int nc = grid[0].size();
        // 刷操作
        grid[r][c] = '0';
        // 没有超过边界且任然为同一岛屿
        // 向左移动
        if (r - 1 >= 0 && grid[r - 1][c] == '1')
        {
            DFS(grid, r - 1, c);
        }
        // 向右移动
        if (r + 1 < nr && grid[r + 1][c] == '1')
        {
            DFS(grid, r + 1, c);
        }
        // 向上移动
        if (c - 1 >= 0 && grid[r][c - 1] == '1')
        {
            DFS(grid, r, c - 1);
        }
        // 向下移动
        if (c + 1 < nc && grid[r][c + 1] == '1')
        {
            DFS(grid, r, c + 1);
        }
    };

    // 广度优先遍历 BFS
    void BFS(vector<vector<char>> &grid, int r, int c)
    {
        // 当前元素先置为0
        grid[r][c] = '0';
        // 获取当前行数列数做边界判断
        int n = grid.size();
        int m = grid[0].size();
        // 记录当前元素的平面坐标
        queue<vector<int>> queue;
        // 将坐标转换为一个数字
        queue.push({r, c});
        while (!queue.empty())
        {
            int i = queue.front()[0];
            int j = queue.front()[1];
            queue.pop();
            // 出界判断+ 刷岛操作 **注意边界条件**
            // 向上移动
            if (i > 0 && grid[i - 1][j] == '1')
            {
                grid[i - 1][j] = '0';
                queue.push({i - 1, j});
            }
            // 向下移动
            if (i < n - 1 && grid[i + 1][j] == '1')
            {
                grid[i + 1][j] = '0';
                queue.push({i + 1, j});
            }
            // 向左移动
            if (j > 0 && grid[i][j - 1] == '1')
            {
                grid[i][j - 1] = '0';
                queue.push({i, j - 1});
            }
            // 向右移动
            if (j < m - 1 && grid[i][j + 1] == '1')
            {
                grid[i][j + 1] = '0';
                queue.push({i, j + 1});
            }
        }
    };

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int nr = grid.size();
        // 去除脏数据
        if (!nr)
        {
            return 0;
        }
        int nc = grid[0].size();
        // 开始扫描图上的所有节点
        for (int r = 0; r < nr; r++)
        {
            for (int c = 0; c < nc; c++)
            {
                // 遇到新的岛屿时 island ++
                if (grid[r][c] == '1')
                {
                    ++island;
                    BFS(grid, r, c);
                }
            }
        }
        return island;
    }
};
// @lc code=end
