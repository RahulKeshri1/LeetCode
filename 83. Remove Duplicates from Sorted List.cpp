/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.



Example 1:

Input: head = [1,1,2]
Output: [1,2]

Example 2:

Input: head = [1,1,2,3,3]
Output: [1,2,3]



Constraints:

    The number of nodes in the list is in the range [0, 300].
    -100 <= Node.val <= 100
    The list is guaranteed to be sorted in ascending order.
*/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

void push(ListNode *&head, int x)
{
    ListNode *n = new ListNode(x);
    if (head == NULL)
    {
        head = n;
        return;
    }
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void print(ListNode *head)
{
    while (head->next != NULL)
    {
        cout << head->val << "-> ";
        head = head->next;
    }
    cout << head->val;
}

ListNode *deleteDuplicates(ListNode *head)

{
    ListNode *temp = head;
    ListNode *dummy = new ListNode(-101);
    ListNode *ans = dummy;
    while (temp)
    {
        if (temp->val != dummy->val)
        {
            ListNode *newnode = new ListNode(temp->val);
            dummy->next = newnode;
            dummy = newnode;
        }
        temp = temp->next;
    }
    return ans->next;
}

int main()
{
    ListNode *head = NULL;
    push(head, 1);
    push(head, 1);
    push(head, 2);

    print(head);
    cout << endl;
    head=deleteDuplicates(head);
    print(head);
    cout << endl;
    return 0;
}