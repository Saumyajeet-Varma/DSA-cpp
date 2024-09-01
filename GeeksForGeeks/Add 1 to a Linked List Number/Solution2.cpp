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
    int getCarry(Node *temp)
    {
        if (temp == NULL)
            return 1;
        int carry = getCarry(temp->next);
        temp->data += carry;
        if (temp->data < 10)
            return 0;
        temp->data = 0;
        return 1;
    }

    Node *addOne(Node *head)
    {
        int carry = getCarry(head);
        if (carry == 0)
            return head;
        Node *newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
};