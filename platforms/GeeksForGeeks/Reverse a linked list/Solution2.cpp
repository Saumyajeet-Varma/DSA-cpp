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
        if (head == NULL || head->next == nullptr)
            return head;
        Node *prevNode = NULL;
        Node *temp = head;
        while (temp != NULL)
        {
            Node *nextNode = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = nextNode;
        }
        return prevNode;
    }
};