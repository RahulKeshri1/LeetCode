/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:

Input: head = [1,2]
Output: [2,1]

Example 3:

Input: head = []
Output: []

 

Constraints:

    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000
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

ListNode *reverseList(ListNode *head)
{
    ListNode *temp = head;
    ListNode *dummy = NULL;
    while (temp)
    {
        ListNode *newnode = new ListNode(temp->val);
        newnode->next = dummy;
        dummy = newnode;
        temp = temp->next;
    }
    return dummy;
}

int main()
{
    ListNode *head = NULL;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 5);

    print(head);
    cout << endl;
    head = reverseList(head);
    print(head);
    cout << endl;
    return 0;
}