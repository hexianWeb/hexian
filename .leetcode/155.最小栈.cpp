#include <algorithm>;
#include <stack>;
using namespace std;
/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack
{
    stack<int> Stack;
    stack<int> min_stack;

public:
    MinStack()
    {
        // 初始化 辅助栈开始填入最大值
        min_stack.push(__INT_MAX__);
    }

    void push(int val)
    {
        // 辅助站始终填入最小值
        Stack.push(val);
        min_stack.push(min(val, min_stack.top()));
    }

    void pop()
    {
        // 栈POP最大值
        Stack.pop();
        // 辅助栈同步弹出
        min_stack.pop();
    }

    int top()
    {
        int top = Stack.top();
        return top;
    }

    int getMin()
    {
        int min = min_stack.top();
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
