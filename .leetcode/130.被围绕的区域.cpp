#include <vector>
#include <queue>
#include <iostream>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution
{
private:
    // 矢量数组
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

public:
    void solve(vector<vector<char>> &board)
    {
        // 矩阵基本信息获取
        int n = board.size();
        int m = board[0].size();
        // 影子矩阵初始化
        vector<vector<int>> shadow(n, vector<int>(m));

        // BFS辅助队列
        queue<vector<int>> queue;

        // 扫描矩阵 获取 边缘'O'字符以及shadow影子辅助矩阵初始化
        for (int r = 0; r < n; r++)
        {
            cout << endl;
            for (int c = 0; c < m; c++)
            {
                if (board[r][c] == 'O')
                {
                    //判断是否处于边缘
                    if (r == 0 || c == 0 || r == n - 1 || c == m - 1)
                    {
                        queue.push({r, c});
                    }
                    shadow[r][c] = 1;
                }
            }
        }

        // BFS处于边缘的数组 将与其同一围绕的区域锁定应的shadow矩阵置为0
        while (!queue.empty())
        {
            // 获取当前边缘“O”的坐标
            int i = queue.front()[0];
            int j = queue.front()[1];
            queue.pop();

            // 自身置为0
            shadow[i][j] = 0;

            // BFS式扩展搜索周围“O”
            for (auto dir : dirs)
            {
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                // 判断是否出界 以及是周边岛屿的一部分
                if (0 <= new_i && new_i < n && 0 <= new_j && new_j < m && shadow[new_i][new_j] == 1)
                {
                    queue.push({new_i, new_j});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (shadow[i][j] == 1)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// @lc code=end
