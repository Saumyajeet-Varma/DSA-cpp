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
    ListNode *sortList(ListNode *head)
    {
        vector<int> nums;
        ListNode *temp = head;
        while (temp != NULL)
        {
            nums.push_back(temp->val);
            temp = temp->next;
        }
        sort(nums.begin(), nums.end());
        temp = head;
        int i = 0;
        while (temp != NULL)
        {
            temp->val = nums[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};