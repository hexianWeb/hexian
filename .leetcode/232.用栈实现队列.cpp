#include <stack>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue
{
public:
    stack<int> StackIn;
    stack<int> StackOut;
    MyQueue()
    {
    }

    void push(int x)
    {
        StackIn.push(x);
    }

    int pop()
    {
        if (StackOut.empty())
        {
            while (!StackIn.empty())
            {
                StackOut.push(StackIn.top());
                StackIn.pop();
            }
        }
        int res = StackOut.top();
        StackOut.pop();
        return res;
    }

    int peek()
    {
        int res = this->pop();
        StackOut.push(res);
        return res;
    }

    bool empty()
    {
        return StackIn.empty() && StackOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
