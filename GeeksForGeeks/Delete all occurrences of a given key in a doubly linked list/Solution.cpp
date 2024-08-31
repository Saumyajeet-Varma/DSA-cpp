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

class Solution
{
public:
    void deleteAllOccurOfX(struct Node **head_ref, int x)
    {
        Node *head = *head_ref;
        Node *temp = head;
        if (head == NULL)
            return;
        while (head != NULL && head->data == x)
        {
            head = head->next;
            head->prev = nullptr;
            delete temp;
            temp = head;
        }
        *head_ref = head;
        while (temp != NULL)
        {
            if (temp->data == x)
            {
                Node *prevNode = temp->prev;
                Node *nextNode = temp->next;
                prevNode->next = nextNode;
                if (nextNode != nullptr)
                    nextNode->prev = prevNode;
                delete temp;
                temp = nextNode;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
};