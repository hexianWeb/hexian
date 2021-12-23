#include <vector>
#include <iostream>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution
{
private:
    // 矢量数组
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    // 出界处理判断函数
    bool inArea(vector<vector<int>> &grid, int r, int c)
    {
        return 0 <= r && r < grid.size() && 0 <= c && c < grid[0].size();
    };
    int getArea(vector<vector<int>> &grid, int r, int c, vector<vector<int>> &visited)
    {
        int area = 0;
        // BFS 辅助队列
        queue<vector<int>> queue;
        // 初始化遇到的节点
        queue.push({r, c});

        visited[r][c] = 1;

        while (!queue.empty())
        // cout << shadow[r][c] << " ";
        {
            int i = queue.front()[0];
            int j = queue.front()[1];
            queue.pop();
            // 当前岛屿面积加一
            area++;
            for (auto dir : dirs)
            {
                // 坐标处理
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                // 当前坐标合格 且坐标未被访问
                if (inArea(grid, new_i, new_j) && grid[new_i][new_j] == 1 && !visited[new_i][new_j])
                {
                    queue.push({new_i, new_j});
                    visited[new_i][new_j] = 1;
                }
            }
        }
        return area;
    };

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        // 当前最大面积岛屿
        int maxArea = 0;
        // 基础信息获取
        int n = grid.size();
        int m = grid[0].size();
        // 已处理节点标记矩阵
        vector<vector<int>> visited(n, vector<int>(m));

        // 扫描图中所有岛屿 并依次比较各面积大小
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                if (grid[r][c] == 1)
                {
                    maxArea = max(maxArea, getArea(grid, r, c, visited));
                }
            }
        }
        return maxArea;
    }
};
// @lc code=end
