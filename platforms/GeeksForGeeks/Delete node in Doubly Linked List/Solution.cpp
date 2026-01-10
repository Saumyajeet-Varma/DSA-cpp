#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution
{
public:
    Node *deleteNode(Node *head, int x)
    {
        Node *temp = head;
        int count = 1;
        while (count < x)
        {
            temp = temp->next;
            count++;
        }
        if (temp->prev == NULL)
        {
            temp->next->prev = nullptr;
            temp = temp->next;
            delete head;
            return temp;
        }
        else
            temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        temp->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return head;
    }
};