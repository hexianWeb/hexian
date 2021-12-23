#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        }
    vector<int> findRedundantConnection2(vector<vector<int>> &edges)
    {
        // 定点数为边数加一
        UnionFind *uf = new UnionFind(edges.size() + 1);
        for (auto &edge : edges)
        {
            int node1 = edge[0];
            int node2 = edge[1];
            if (!uf->is_same(node1, node2))
            {
                uf->to_union(node1, node2);
            }
            else
            {
                return edge;
            }
        }
        return vector<int>{};
    }
    class UnionFind
    {
    private:
        vector<int> root;
        vector<int> rank; //标记当前所在集合的高度（秩）

    public:
        // 冒号后 初始化 两个数组
        UnionFind(int size) : root(vector<int>(size)), rank(vector<int>(size))
        {
            // 初始化每一个元素的根节点都为自身
            for (int i = 0; i < size; i++)
            {
                root[i] = i;
                rank[i] = 1;
            }
        }
        int find(int x)
        {
            return root[x] == x ? x : find(root[x]);
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
                    root[rootY] = rootX;
                    rank[rootX] += 1;
                }
            }
        }
        bool is_same(int e1, int e2)
        {
            return find(e1) == find(e2);
        }
    };
};
// @lc code=end
