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
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *curr = head;
        ListNode *prevNode = nullptr;

        while (curr)
        {
            ListNode *nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
        }

        return prevNode;
    }
};