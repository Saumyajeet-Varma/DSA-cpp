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
    int sizeLL(ListNode *head)
    {
        int n = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            n++;
        }
        return n;
    }

    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ans(k, NULL);
        int n = sizeLL(head);
        int size = n / k;
        int extra = n % k;
        ListNode *curr = head;
        for (int i = 0; i < k; i++)
        {
            ListNode *partHead = curr;
            int partLen = size + (extra > 0 ? 1 : 0);
            extra--;
            for (int j = 1; j < partLen; j++)
            {
                if (curr != NULL)
                    curr = curr->next;
            }
            if (curr != NULL)
            {
                ListNode *nextPartHead = curr->next;
                curr->next = nullptr;
                curr = nextPartHead;
            }
            ans[i] = partHead;
        }
        return ans;
    }
};