#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

class Solution
{
public:
    Node *constructDLL(vector<int> &arr)
    {
        Node *head = new Node(arr[0]);
        Node *temp = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *newNode = new Node(arr[i]);
            newNode->prev = temp;
            temp->next = newNode;
            temp = temp->next;
        }
        return head;
    }
};