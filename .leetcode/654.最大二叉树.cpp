#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        TreeNode *newNode = new TreeNode(0);

        int size = nums.size();
        if (size == 1)
        {
            newNode->val = nums[0];
            return newNode;
        }
        // 数组长度大于等于1时
        int maxNum = 0;
        // 用于分割数组的下标
        int index = 0;
        for (int i = 0; i < size; i++)
        {
            if (maxNum < nums[i])
            {
                maxNum = nums[i];
                index = i;
            }
        }
        newNode->val = maxNum;
        if (index > 0)
        {
            // 将左数组分割出来 递归调用自身
            vector<int> newVec(nums.begin(), nums.begin() + index);
            newNode->left = constructMaximumBinaryTree(newVec);
        }
        if (index < size - 1)
        {
            // 将右数组分割出来 递归调用自身
            vector<int> newVec(nums.begin() + index + 1, nums.end());
            newNode->right = constructMaximumBinaryTree(newVec);
        }
        return newNode;
    }
};
// @lc code=end
