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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || !head->next || left == right)
            return head;

        ListNode *dummyHead = new ListNode(0, head);
        ListNode *prevNode = dummyHead;

        int count = 1;

        while (count < left)
        {
            prevNode = prevNode->next;
            count++;
        }

        ListNode *curr = prevNode->next;
        ListNode *prev = nullptr;

        count = 0;

        while (count <= right - left)
        {
            ListNode *next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;

            count++;
        }

        prevNode->next->next = curr;
        prevNode->next = prev;

        return dummyHead->next;
    }
};