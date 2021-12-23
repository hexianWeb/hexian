#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
class Solution
{
private:
    bool dfs(vector<vector<int>> &graph, int i, int col, vector<int> &column)
    {
        // 集合归类操作
        if (column[i] != 0)
        {
            return column[i] == col;
        }
        column[i] = col;

        for (int index : graph[i])
        {
            //如果邻居节点产生集合冲突 与当前节点在同一集合 则失败
            if (!dfs(graph, index, -col, column))
            {
                return false;
            };
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        // 集合记录数组+节点访问记录数组
        vector<int> column(n, 0);
        // BFS 辅助队列
        queue<int> queue;
        // 遍历图中所有节点 确保没有多个联通分量
        for (int i = 0; i < graph.size(); i++)
        {
            if (column[i] != 0)
            {
                continue;
            }
            queue.push(i);
            column[i] = 1;
            while (!queue.empty())
            {
                int node = queue.front(); //当前节点 node
                queue.pop();
                for (int index : graph[node])
                {
                    // 邻居节点已有集合 且与当前节点统一集合
                    if (column[index] == column[node])
                    {
                        return false;
                    }
                    // 邻居节点没有集合 集合归类
                    if (column[index] == 0)
                    {
                        column[index] = -column[node];
                        queue.push(index);
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite2(vector<vector<int>> &graph)
    {

        int n = graph.size();
        // 集合记录数组+节点访问记录数组
        vector<int> column(n, 0);
        // 遍历图中所有节点 确保没有多个联通分量
        for (int i = 0; i < n; i++)
        {
            // 该节点尚未经过处理
            if (column[i] == 0 && !dfs(graph, i, 1, column))
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
