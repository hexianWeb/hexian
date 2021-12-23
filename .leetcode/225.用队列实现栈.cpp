#include <queue>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
// 队列和栈的数据结构截然不同
// 所以在用队列实现栈的时候两个队列和一个队列毫无意义
// 因为队列的性质是先进先出 所以多个队列不会改变数据的走向
// 这里我们用一个queue stack和pop的操作不同在于pop操作
// 将队列元素的个数记录下来 对头元素取出重新插入队尾 重复n-1次
// 第n各元素提出 即可
class MyStack
{
public:
    queue<int> queue;
    MyStack()
    {
    }

    void push(int x)
    {
        queue.push(x);
    }

    int pop()
    {
        int num = queue.size();
        num = num - 1;
        while (num--)
        {
            int temp = queue.front();
            queue.pop();
            queue.push(temp);
        }
        int ans = queue.front();
        queue.pop();
        return ans;
    }

    int top()
    {
        // 可复用pop方法 随后将其再push回去
        int ans = this->pop();
        queue.push(ans);
        return ans;
    }

    bool empty()
    {
        if (queue.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
