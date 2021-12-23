#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return BST(nums, 0, nums.size() - 1);
    }
    TreeNode *BST(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int mid = (right +
                   left) /
                  2;
        cout << mid << endl;
        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left = BST(nums, left, mid - 1);
        cur->right = BST(nums, mid + 1, right);
        return cur;
    }
};
// @lc code=end
