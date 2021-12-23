#include <vector>
#include <queue>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
// 太平洋 sea
// 大西洋 ocean
class Solution
{
private:
    bool inArea(vector<vector<int>> &grid, int r, int c)
    {
        return 0 <= r && r < grid.size() && 0 <= c && c < grid[0].size();
    };
    // 矢量数组
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &map)
    {
        // 基本info
        int n = map.size();
        int m = map[0].size();

        // 初始化
        vector<vector<int>> shadow_sea(n, vector<int>(m));
        vector<vector<int>> shadow_ocean(n, vector<int>(m));

        // BFS辅助队列 双向 多源BFS
        queue<pair<int, int>> sea;
        queue<pair<int, int>> ocean;

        // 答案数组
        vector<vector<int>> res;
        //遍历map 映射shadow_sea 并且初始化BFS辅助队列
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                // 太平洋映射
                if (r == 0 || c == 0)
                {
                    // 标记已访问节点
                    // shadow_sea[r][c] = 1;
                    // 将符合的节点纳入访问队列
                    sea.emplace(r, c);
                }
                // 大西洋映射
                if (r == n - 1 || c == m - 1)
                {
                    // shadow_ocean[r][c] = 1;
                    ocean.emplace(r, c);
                }
            }
        }

        // 对太平洋的多源BFS
        while (!sea.empty())
        {
            auto elem = sea.front();
            int i = elem.first;
            int j = elem.second;
            sea.pop();
            shadow_sea[i][j] = 1;
            for (auto dir : dirs)
            {
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                // 坐标合格且当前新坐标的水可以流向当前坐标外加当前坐标未被访问
                if (inArea(map, new_i, new_j) && map[new_i][new_j] >= map[i][j] && !shadow_sea[new_i][new_j])
                {
                    sea.emplace(new_i, new_j);
                    shadow_sea[new_i][new_j] = 1;
                }
            }
        }

        // 对大西洋的多源BFS
        while (!ocean.empty())
        {
            auto elem = ocean.front();
            int i = elem.first;
            int j = elem.second;
            ocean.pop();
            shadow_ocean[i][j] = 1;
            for (auto dir : dirs)
            {
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                if (inArea(map, new_i, new_j) && map[new_i][new_j] >= map[i][j] && !shadow_ocean[new_i][new_j])
                {
                    ocean.emplace(new_i, new_j);
                    shadow_ocean[new_i][new_j] = 1;
                }
            }
        }

        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                if (shadow_sea[r][c] == 1 && shadow_ocean[r][c] == 1)
                {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }
};
// @lc code=end
