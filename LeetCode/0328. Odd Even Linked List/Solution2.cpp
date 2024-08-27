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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return head;
        vector<int> nums;
        ListNode *temp = head;
        while (temp != NULL && temp->next != NULL)
        {
            nums.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp != NULL)
            nums.push_back(temp->val);
        temp = head->next;
        while (temp != NULL && temp->next != NULL)
        {
            nums.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp != NULL)
            nums.push_back(temp->val);
        temp = head;
        for (int i = 0; i < nums.size(); i++)
        {
            temp->val = nums[i];
            temp = temp->next;
        }
        return head;
    }
};