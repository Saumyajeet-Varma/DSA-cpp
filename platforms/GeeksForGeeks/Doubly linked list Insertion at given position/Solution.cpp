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
        next = prev = NULL;
    }
};

void addNode(Node *head, int pos, int data)
{
    int count = 0;
    Node *temp = head;
    while (count < pos)
    {
        temp = temp->next;
        count++;
    }
    Node *newNode = new Node(data);
    newNode->prev = temp;
    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}