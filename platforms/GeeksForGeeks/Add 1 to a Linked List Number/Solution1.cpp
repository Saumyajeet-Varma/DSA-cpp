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
    Node *reverseLL(Node *head)
    {
        if (head == NULL || head->next == nullptr)
            return head;
        Node *temp = head;
        Node *prevNode = NULL;
        while (temp != NULL)
        {
            Node *nextNode = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = nextNode;
        }
        return prevNode;
    }

    Node *addOne(Node *head)
    {
        head = reverseLL(head);
        Node *temp = head;
        int carry = 1;
        while (temp != NULL)
        {
            temp->data = temp->data + carry;
            if (temp->data < 10)
            {
                carry = 0;
                break;
            }
            else
            {
                carry = 1;
                temp->data = 0;
            }
            temp = temp->next;
        }
        if (carry == 1)
        {
            Node *newNode = new Node(1);
            head = reverseLL(head);
            newNode->next = head;
            return newNode;
        }
        head = reverseLL(head);
        return head;
    }
};