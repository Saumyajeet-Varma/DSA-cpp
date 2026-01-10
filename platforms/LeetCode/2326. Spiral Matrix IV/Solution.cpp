#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> mat(m, vector<int>(n));
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        int value = head->val;
        ListNode *temp = head;
        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; i++)
            {
                (temp ? value = temp->val : value = -1);
                mat[top][i] = value;
                if (temp)
                    temp = temp->next;
            }
            top++;
            for (int i = top; i <= bottom; i++)
            {
                (temp ? value = temp->val : value = -1);
                mat[i][right] = value;
                if (temp)
                    temp = temp->next;
            }
            right--;
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    (temp ? value = temp->val : value = -1);
                    mat[bottom][i] = value;
                    if (temp)
                        temp = temp->next;
                }
                bottom--;
            }
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    (temp ? value = temp->val : value = -1);
                    mat[i][left] = value;
                    if (temp)
                        temp = temp->next;
                }
                left++;
            }
        }
        return mat;
    }
};