#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

vector<int> noSibling(Node *node)
{
    if (!node)
        return {-1};
    vector<int> result;
    queue<Node *> que;
    que.push(node);
    while (!que.empty())
    {
        Node *currNode = que.front();
        que.pop();
        if (currNode->left)
        {
            que.push(currNode->left);
            if (!currNode->right)
                result.push_back(currNode->left->data);
        }
        if (currNode->right)
        {
            que.push(currNode->right);
            if (!currNode->left)
                result.push_back(currNode->right->data);
        }
    }
    if (result.empty())
        return {-1};
    sort(result.begin(), result.end());
    return result;
}