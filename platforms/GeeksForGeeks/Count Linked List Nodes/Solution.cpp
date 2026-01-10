struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class Solution
{
public:
    int getCount(struct Node *head)
    {
        Node *temp = head;
        int n = 0;
        while (temp)
        {
            n++;
            temp = temp->next;
        }
        return n;
    }
};