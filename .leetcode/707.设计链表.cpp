#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList
{
    // 定义一个结构体
    struct node
    {
        int val;
        node *next;
        // 构造器
        node(int x) : val(x), next(nullptr) {}
    };

private:
    node *head;
    int length;

public:
    // 初始化一个函数
    // 这里将第一个结点定为0相当于创立一个带头结点且仅有头结点的单链表
    MyLinkedList()
    {
        // node *head = (node *)malloc(sizeof(node));
        head = new node(0);
        // 定义初始长度为0
        length = 0;
    }

    // 获取链表中的第index个节点 如果索引无效则返回
    int get(int index)
    {
        // 索引无效
        if (index < 0 || index > (length - 1))
        {
            return -1;
        }
        node *cur = head;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    // 头插法插入该节点
    void addAtHead(int val)
    {
        // 创立一个新的节点addNode
        node *addNode = new node(val);
        // 头插法常规操作了
        addNode->next = head->next;
        head->next = addNode;
        length++;
    }

    // 尾插法插入节点
    void addAtTail(int val)
    {
        node *addNode = new node(val);
        node *cur = head;
        while (cur->next)
        {
            cur = cur->next;
        }
        addNode->next = cur->next;
        cur->next = addNode;
        length++;
    }

    // 在中途的某个节点插入
    void addAtIndex(int index, int val)
    {
        // 分四种情况
        if (index <= 0)
        {
            addAtHead(val);
        }
        else if (index == length)
        {
            addAtTail(val);
        }
        else if (index > length)
        {
            return;
        }
        else
        {
            node *newnode = new node(val);
            node *cur = head;
            while (index--)
            {
                cur = cur->next;
            }
            newnode->next = cur->next;
            cur->next = newnode;
            length++;
        }
    }
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= length)
            return;
        node *cur = head; //从头指针开始
        while (index--)
        { //遍历到index-1的位置,循环次数是index次
            cur = cur->next;
        }
        cur->next = cur->next->next; //相当于直接跨过了index节点
        length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
