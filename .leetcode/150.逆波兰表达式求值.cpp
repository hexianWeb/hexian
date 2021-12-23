#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution
{
private:
    // 定义操作数一 操作数二以及返还数
    int op_num1 = 0;
    int op_num2 = 0;
    int op_num = 0;
    // 将所有的操作数存入stack中
    stack<int> Stack;

public:
    int evalRPN(vector<string> &tokens)
    {
        for (string token : tokens)
        {
            if (token == "+")
            {
                op_num1 = Stack.top();
                Stack.pop();
                op_num2 = Stack.top();
                Stack.pop();
                op_num = op_num1 + op_num2;
                Stack.push(op_num);
            }
            else if (token == "-")
            {
                op_num1 = Stack.top();
                Stack.pop();
                op_num2 = Stack.top();
                Stack.pop();
                op_num = op_num2 - op_num1;
                Stack.push(op_num);
            }
            else if (token == "*")
            {
                op_num1 = Stack.top();
                Stack.pop();
                op_num2 = Stack.top();
                Stack.pop();
                op_num = op_num1 * op_num2;
                Stack.push(op_num);
            }
            else if (token == "/")
            {
                op_num1 = Stack.top();
                Stack.pop();
                op_num2 = Stack.top();
                Stack.pop();
                op_num = op_num2 / op_num1;
                Stack.push(op_num);
            }
            else
            {
                // 　　显然，atoi需要的事const char*类型，而我上面给的上string类型，
                // 所以就要 多加一个函数string.c_str()。
                // string.c_str是Borland封装的String类中的一个函数，
                // 它返回当前字符串的首字符地址。
                cout << atoi(token.c_str()) << " ";
                Stack.push(atoi(token.c_str()));
            }
        }
        return Stack.top();
    }
};
// @lc code=end
