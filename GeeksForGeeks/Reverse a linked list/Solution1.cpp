#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class Solution
{
public:
    struct Node *reverseList(struct Node *head)
    {
        stack<int> stk;
        Node *temp = head;
        while (temp != NULL)
        {
            stk.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            temp->data = stk.top();
            stk.pop();
            temp = temp->next;
        }
        return head;
    }
};