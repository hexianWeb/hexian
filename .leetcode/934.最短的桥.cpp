#include <vector>
#include <queue>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution
{
private:
    // 定义结构体
    struct Node
    {
        int x, y, level;
        Node(int x, int y, int level) : x(x), y(y), level(level) {}
    };

    // 矢量数组
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    // 判断是否出界函数
    bool inArea(vector<vector<int>> &grid, int i, int j)
    {
        return 0 <= i && i < grid.size() && 0 <= j && j < grid[0].size();
    }
    void DFS(vector<vector<int>> &grid, int r, int c)
    {
        // 刷岛操作 将同一个岛的所有元素都置为2
        grid[r][c] = 2;
        // 探岛操作
        for (auto dir : dirs)
        {
            int new_r = r + dir[0];
            int new_c = c + dir[1];
            if (inArea(grid, new_r, new_c) && grid[new_r][new_c] == 1)
            {
                DFS(grid, new_r, new_c);
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        // 岛屿基本info
        int n = grid.size();
        int m = grid[0].size();

        // 跳出循环用
        bool flag = false;

        // bfs 辅助队列 =>坐标以及层数
        queue<Node *> queue;

        // 找到其中一座岛 并将其全部改成2
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                if (grid[r][c] == 1)
                {
                    flag = true;
                    DFS(grid, r, c);
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }

        // BFS遍历前准备工作
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                if (grid[r][c] == 2)
                {
                    Node *node = new Node(r, c, 0);
                    queue.push(node);
                }
            }
        }
        int count = 0;
        // 重置flag 跳出循环
        flag = false;
        while (!queue.empty())
        {
            Node *cur = queue.front();
            queue.pop();
            int i = cur->x;
            int j = cur->y;
            int level = cur->level;
            for (auto dir : dirs)
            {
                int new_i = dir[0] + i;
                int new_j = dir[1] + j;
                if (inArea(grid, new_i, new_j))
                {
                    if (grid[new_i][new_j] == 0)
                    {
                        Node *temp = new Node(new_i, new_j, level + 1);
                        queue.push(temp);
                        grid[new_i][new_j] = 2;
                    }
                    if (grid[new_i][new_j] == 1)
                    {
                        count = level;
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)
            {
                break;
            }
        }

        return count;
    }
};
// @lc code=end