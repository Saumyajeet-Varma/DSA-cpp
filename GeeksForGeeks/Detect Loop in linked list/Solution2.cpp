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
    bool detectLoop(Node *head)
    {
        unordered_map<Node *, int> visited;
        Node *temp = head;
        while (temp != NULL)
        {
            if (visited[temp] == 1)
                return true;
            visited[temp]++;
            temp = temp->next;
        }
        return false;
    }
};