#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 方法一
// 遍历整颗树 用map记录下各值的出现频率 取其中最高的
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution
{
private:
    int maxCount; //最大频率
    int count;    //统计频率
    TreeNode *pre;
    vector<int> result;
    void SearchBST(TreeNode *cur)
    {
        if (!cur)
        {
            return;
        }
        SearchBST(cur->left);

        // 如果当前是第一个节点
        if (pre == nullptr)
        {
            count = 1;
        }
        // 当前节点和前一个节点相同
        else if (cur->val == pre->val)
        {
            count++;
        }
        // 当前节点的值未出现过
        else
        {
            count = 1;
        }

        pre = cur;

        if (count == maxCount)
        {
            result.push_back(cur->val);
        }
        if (count > maxCount)
        {
            maxCount = count; //更新最大频率
            result.clear();
            result.push_back(cur->val);
        }

        SearchBST(cur->right);
        return;
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        count = 0;
        maxCount = 0;
        TreeNode *pre = nullptr;
        result.clear();
        SearchBST(root);
        return result;
    }
};
// @lc code=end
