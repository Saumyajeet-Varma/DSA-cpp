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
    int countNodesinLoop(struct Node *head)
    {
        unordered_map<Node *, int> mpp;
        Node *temp = head;
        int timer = 1;
        while (temp != NULL)
        {
            if (mpp.find(temp) != mpp.end())
            {
                return timer - mpp[temp];
            }
            mpp[temp] = timer;
            timer++;
            temp = temp->next;
        }
        return 0;
    }
};