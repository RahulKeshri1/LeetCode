#include <iostream>
#include <unordered_map>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

void Print(ListNode *head)
{
    ListNode *temp = head;
    while (temp->next)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << temp->val << endl;
}

ListNode *insert(ListNode *&head, int x)
{
    ListNode *newnode = new ListNode(x);
    if (head == NULL)
    {
        head = newnode;
        return newnode;
    }
    ListNode *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return newnode;
}

ListNode *detectCycle(ListNode *head)
{
    ListNode *temp = head;
    unordered_map<ListNode *, int> ma;
    // int index=0;
    while (temp)
    {
        if (ma[temp] == 0)
        {
            ma[temp]++;
        }
        else
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main()
{
    ListNode *head = NULL;
    ListNode *n1;
    insert(head, 1);
    n1 = insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5)->next = n1;

    cout << detectCycle(head)->val;
    return 0;
}