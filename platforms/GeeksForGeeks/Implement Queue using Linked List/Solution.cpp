#include <bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue
{
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() { front = rear = NULL; }
};

void MyQueue::push(int x)
{
    QueueNode *newNode = new QueueNode(x);
    if (rear == NULL)
    {
        rear = newNode;
        front = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int MyQueue ::pop()
{
    if (front == NULL)
    {
        return -1;
    }
    QueueNode *delNode = front;
    int el = delNode->data;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    delete delNode;
    return el;
}