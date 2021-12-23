#include <vector>
#include <iostream>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution
{
private:
    // 向量
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        // BFS queue
        queue<vector<int>> queue;
        // 获取长宽 遍历图
        int n = mat.size();
        int m = mat[0].size();
        // 距离存储矩阵
        vector<vector<int>> dist(n, vector<int>(m));
        // 已访问节点标记矩阵
        vector<vector<int>> visited(n, vector<int>(m));
        // 取得所有0点 放入初始队列
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                if (mat[r][c] == 0)
                {
                    queue.push({r, c});
                    //即已经访问的节点标记为1
                    visited[r][c] = 1;
                }
            }
        }

        while (!queue.empty())
        {
            int i = queue.front()[0];
            int j = queue.front()[1];
            queue.pop();
            // 刷岛操作 注意判断边界条件和是否重复入栈
            for (int d = 0; d < 4; d++)
            {
                // 对[i,j]坐标进行矢量操作
                int new_i = i + dirs[d][0];
                int new_j = j + dirs[d][1];
                //
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && visited[new_i][new_j] != 1)
                {
                    // 更新距离矩阵以及已处理节点矩阵
                    dist[new_i][new_j] = dist[i][j] + 1;
                    queue.push({new_i, new_j});
                    visited[new_i][new_j] = 1;
                }
            }
        }
        return dist;
    }
};
// @lc code=end
