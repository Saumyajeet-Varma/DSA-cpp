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
    Node *sortedInsert(struct Node *head, int x)
    {
        Node *newNode = new Node(x);
        Node *temp = head;
        if (head)
        {
            if (head->data > x)
            {
                newNode->next = head;
                return newNode;
            }
            while (temp->next)
            {
                if (temp->next->data > x)
                {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    return head;
                }
                temp = temp->next;
            }
            temp->next = newNode;
            return head;
        }
        return newNode;
    }
};