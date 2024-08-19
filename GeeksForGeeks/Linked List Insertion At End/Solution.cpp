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
    Node *insertAtEnd(Node *head, int x)
    {
        Node *newNode = new Node(x);
        if (head == NULL)
            return newNode;
        Node *end = head;
        while (end->next)
        {
            end = end->next;
        }
        end->next = newNode;
        return head;
    }
};