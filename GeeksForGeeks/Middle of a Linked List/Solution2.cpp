#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    int getMiddle(Node *head)
    {
        if (head == NULL)
            return -1;
        int len = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        int count = 0;
        temp = head;
        while (count < len / 2)
        {
            count++;
            temp = temp->next;
        }
        return temp->data;
    }
};