#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
class Solution
{
private:
    // 矢量数组
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    // 出界判断
    bool inArea(vector<vector<int>> &grid, int r, int c)
    {
        return 0 <= r && r < grid.size() && 0 <= c && c < grid[0].size();
    };

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int ans = 0;
        // 基础信息
        int n = grid.size();
        int m = grid[0].size();
        // 记录已经访问过的节点的矩阵
        // vector<vector<int>> visited(n, vector<int>(m));

        // BFS辅助栈
        queue<pair<int, int>> queue;
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                if ((r == 0 || c == 0 || r == n - 1 || c == m - 1) && grid[r][c] == 1)
                {
                    queue.emplace(r, c);
                    grid[r][c] = 0;
                }
            }
        }

        // BFS
        while (!queue.empty())
        {
            auto elem = queue.front();
            int i = elem.first;
            int j = elem.second;
            queue.pop();
            for (auto dir : dirs)
            {
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                if (inArea(grid, new_i, new_j) && grid[new_i][new_j] == 1)
                {
                    queue.emplace(new_i, new_j);
                    grid[new_i][new_j] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
