#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

// @lc code=start

class Solution
{
public:
    struct Edge
    {
        int point1;
        int point2;
        int cost;
    };
    class UnionFind
    {
    private:
        vector<int> root;
        // 添加了rank数组 来记录每个顶点的高度也就是每个顶点的秩
        vector<int> rank;

    public:
        UnionFind(int size) : root(vector<int>(size)), rank(vector<int>(size))
        {
            for (int i = 0; i < size; i++)
            {
                root[i] = i;
                rank[i] = 1;
            }
        }
        int find(int x)
        {
            if (root[x] == x)
            {
                return x;
            }
            return root[x] = find(root[x]);
        }

        void to_union(int x1, int x2)
        {
            int rootX = find(x1);
            int rootY = find(x2);
            if (rootX != rootY)
            {
                if (rank[rootX] > rank[rootY])
                {
                    root[rootY] = rootX;
                }
                else if (rank[rootX] < rank[rootY])
                {
                    root[rootX] = rootY;
                }
                else
                {
                    root[rootX] = rootY;
                    rank[rootY] += 1;
                }
            }
        }
        bool is_same(int x, int y)
        {
            return find(x) == find(y);
        }
    };
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int size = points.size();
        // 建立并查集
        UnionFind *unionFind = new UnionFind(size);
        // 建立边集数据集
        vector<Edge> edges;
        // 求出每两个点之间的曼哈顿距离
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                vector<int> op1 = points[i];
                vector<int> op2 = points[j];
                // 计算曼哈顿距离
                int cost = abs(op1[0] - op2[0]) + abs(op1[1] - op2[1]);
                // cout << i << " " << j << " " << cost << endl;
                Edge edge = {i, j, cost};
                edges.emplace_back(edge);
            }
        }
        // 按边长度排序
        sort(edges.begin(), edges.end(), [](const auto &a, const auto &b)
             { return a.cost < b.cost; });

        int res = 0;
        int count = size - 1;
        while (edges.size() > 0 && count > 0)
        {
            Edge e = edges.front();
            edges.erase(edges.begin());
            if (!unionFind->is_same(e.point1, e.point2))
            {
                unionFind->to_union(e.point1, e.point2);
                res += e.cost;
                count--;
            }
        }
        return res;
        // 连通分量合并
    }
};
// @lc code=end
