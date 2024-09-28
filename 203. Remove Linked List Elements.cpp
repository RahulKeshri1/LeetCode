/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:

Input: head = [], val = 1
Output: []

Example 3:

Input: head = [7,7,7,7], val = 7
Output: []

 

Constraints:

    The number of nodes in the list is in the range [0, 104].
    1 <= Node.val <= 50
    0 <= val <= 50
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

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *temp = head;
    ListNode *dummy = new ListNode(0);
    ListNode *ans = dummy;
    while (temp)
    {
        if (temp->val != val)
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
    push(head, 2);
    push(head, 6);
    push(head, 3);
    push(head, 4);
    push(head, 5);
    push(head, 6);

    print(head);
    cout << endl;
    head = removeElements(head,6);
    print(head);
    cout << endl;
    return 0;
}