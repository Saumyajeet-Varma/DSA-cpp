#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    bool isPalindrome(Node *head)
    {
        stack<int> stk;

        Node *temp = head;

        while (temp)
        {
            stk.push(temp->data);
            temp = temp->next;
        }

        temp = head;

        while (temp)
        {
            if (temp->data != stk.top())
                return false;

            stk.pop();
            temp = temp->next;
        }

        return true;
    }
};