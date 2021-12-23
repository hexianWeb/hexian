#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        string start_Str = "0000";
        unordered_set<string> deadset;
        // 建立deadset 死锁集合
        for (int i = 0; i < deadends.size(); i++)
        {
            deadset.insert(deadends[i]);
        }

        // 首先需要排除开局死锁的情况 即0000在deadends中
        if (deadset.count(start_Str))
        {
            return -1;
        }

        // 创建BFS的辅助队列
        queue<string> queue;
        // 以及记录访问过过的的节点的队列
        unordered_set<string> visited;

        // 初始化 将根节点拉入
        queue.push(start_Str);
        visited.insert(start_Str);

        int step = 0;

        // BFS
        while (!queue.empty())
        {
            // 记录该层有多少个需要转锁的情况
            int size = queue.size();
            // 遍历该层的每个节点
            while (size-- > 0)
            {
                // cout << size << endl;
                string cur = queue.front();
                queue.pop();
                // 返回已找到节点
                if (cur == target)
                {
                    return step;
                }

                for (int i = 0; i < 4; i++)
                {
                    int num;
                    // 双向隐式转换
                    int curNum = cur[i] - '0';
                    cout << curNum;

                    // 加一操作
                    curNum = curNum == 9 ? 0 : curNum++;
                    cur[i] = curNum + '0';
                    string strAdd = cur;

                    // 减一操作
                    curNum = curNum == 0 ? 9 : curNum--;
                    cur[i] = curNum + '0';
                    string strDel = cur;
                    // 判断加一操作是否在 死锁或已经出现过 在则不能做任何操作
                    if (!deadset.count(strAdd) && !visited.count(strAdd))
                    {
                        queue.push(strAdd);
                        visited.insert(strAdd);
                    }

                    // 减一同上
                    if (!deadset.count(strDel) && !visited.count(strDel))
                    {
                        queue.push(strDel);
                        visited.insert(strDel);
                    }
                }
            }
            step++;
        }

        return -1;
    }
};
// @lc code=end
