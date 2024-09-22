#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));

    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return (node);
};

class Solution
{
public:
    void create_tree(node *root, vector<int> &vec)
    {
        root->data = vec[0];
        root->left = newNode(vec[1]);
        root->right = newNode(vec[2]);
        root->left->left = newNode(vec[3]);
        root->left->right = newNode(vec[4]);
        root->right->left = newNode(vec[5]);
        root->right->right = newNode(vec[6]);
    }
};