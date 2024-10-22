#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void bfs(TreeNode *root, int k, auto &pq)
    {
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int n = que.size();
            long long sum = 0;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                sum += node->val;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            pq.push(sum);
            if (pq.size() > k)
                pq.pop();
        }
    }

    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        bfs(root, k, pq);
        return pq.size() < k ? -1 : pq.top();
    }
};