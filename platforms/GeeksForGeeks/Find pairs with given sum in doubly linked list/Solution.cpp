#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> result;
        if (head == NULL)
            return result;
        Node *left = head;
        Node *right = head;
        while (right->next != NULL)
        {
            right = right->next;
        }
        while (left != right && right->next != left)
        {
            int sum = left->data + right->data;
            if (sum < target)
                left = left->next;
            else if (sum > target)
                right = right->prev;
            else
            {
                result.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
        }
        return result;
    }
};