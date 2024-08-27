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
    Node *segregate(Node *head)
    {
        vector<int> nums;
        Node *temp = head;
        while (temp != NULL)
        {
            nums.push_back(temp->data);
            temp = temp->next;
        }
        sort(nums.begin(), nums.end());
        temp = head;
        int i = 0;
        while (temp != NULL)
        {
            temp->data = nums[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};