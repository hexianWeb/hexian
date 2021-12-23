#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
// 算法思路
// 设定初始时 各个节点都为独立省份 则开始时有N个省份
// 扫描整张表将有关系的节点归纳为一个集合内 每归纳一次 省份数量减一

class UnionFind
{
private:
    vector<int> root;
    vector<int> rank;
    int nums;

public:
    UnionFind(int size) : root(vector<int>(size)), rank(vector<int>(size))
    {
        // 初始化省份数量
        nums = size;
        // 初始化并查集
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
    void to_union(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
            {
                root[rootY] = rootX;
            }
            else if (rank[rootY] > rank[rootX])
            {
                root[rootX] = rootY;
            }
            else
            {
                root[rootX] = rootY;
                rank[rootY] += 1;
            }
            // 只要在融合时发现两个节点属于不同的集合 则nums减少一
            nums--;
        }
    }
    bool is_same(int x, int y)
    {
        return find(x) == find(y);
    }
    int getNums()
    {
        return this->nums;
    }
};
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        UnionFind *uf = new UnionFind(isConnected.size());
        for (int r = 0; r < isConnected.size(); r++)
        {
            for (int c = 0; c < isConnected.size(); c++)
            {
                if (isConnected[r][c] == 1)
                {
                    // 对r行对应城市 和 c列对应城市进行融合
                    uf->to_union(r, c);
                }
            }
        }
        return uf->getNums();
    }
};
// @lc code=end
