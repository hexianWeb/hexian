/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 方法二：一次遍历
// 既然p和q一定存在与树root中
// 我可以从根节点触发 遍历出同时符合p和q的节点的值
// 如果值大于p和q 则说明此时答案 ans节点应该在当前节点的左子树
// 如果cur小于p和q 则ans节点在当前的节点的右子树
// 不满足上述条件是 只可能为
// 情况一
// 当前节点为分叉节点 即为祖先节点
// 二 p与q的其中一个节点就是祖先节点
class Solution
{
private:
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ans = root;
        while (true)
        {
            if (p->val < ans->val && q->val < ans->val)
            {
                ans = ans->left;
            }
            else if (p->val > ans->val && q->val > ans->val)
            {
                ans = ans->right;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end
