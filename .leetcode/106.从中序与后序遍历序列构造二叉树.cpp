#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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

class Solution
{
public:
    TreeNode *traversal(vector<int> &inorder, vector<int> &postorder)
    {
        // 如果数组大小为0 则为空节点
        if (postorder.size() == 0)
        {
            cout << "空节点已返回" << endl;
            return nullptr;
        }

        // 不为空时 ，则后序数组的最后一个元素作为分割节点
        int lastPost = postorder.back();
        cout << "最后一个元素分割点" << lastPost << endl;
        // 构建出当前节点
        TreeNode *cur = new TreeNode(lastPost);
        cout << cur->val << "节点已经创建" << endl;
        if (postorder.size() == 1)
        {
            cout << "节点" << cur->val << "已经创建" << endl;
            return cur;
        }

        // 开始以最后一个后序遍历的元素切割中序数组
        int Index; // 切割点的数组下标
        int inorderSize = inorder.size();
        for (int i = 0; i < inorderSize; i++)
        {
            if (inorder[i] == lastPost)
            {
                Index = i;
                cout << "中序切割点：" << inorder[Index] << endl;
                break;
            }
        }

        // 开始切割
        vector<int> LeftInorder(inorder.begin(), inorder.begin() + Index);
        vector<int> RightInorder(inorder.begin() + Index + 1, inorder.end());

        // 因为当前后序遍历最后一个节点已经实现 故数组中去掉
        postorder.pop_back();
        // 切割后序数组
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + LeftInorder.size());
        vector<int> RightPostorder(postorder.begin() + LeftInorder.size(), postorder.end());

        // 递归调用
        cur->left = traversal(LeftInorder, leftPostorder);
        cur->right = traversal(RightInorder, RightPostorder);

        return cur;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0 || postorder.size() == 0)
        {
            return nullptr;
        }
        return traversal(inorder, postorder);
    }
};
// @lc code=end
