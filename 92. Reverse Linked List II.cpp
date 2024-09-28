/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]

 

Constraints:

    The number of nodes in the list is n.
    1 <= n <= 500
    -500 <= Node.val <= 500
    1 <= left <= right <= n
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

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    ListNode *temp = head;
    ListNode *dummy = new ListNode(0);
    ListNode *ans = dummy;
    int counter = 1;
    while (counter < left)
    {
        ListNode *newnode = new ListNode(temp->val);
        dummy->next = newnode;
        dummy = newnode;
        temp = temp->next;
        counter++;
    }
    ListNode *dummy2 = NULL;
    while (counter <= right)
    {
        ListNode *newnode = new ListNode(temp->val);
        newnode->next = dummy2;
        dummy2 = newnode;
        counter++;
        temp = temp->next;
    }
    dummy->next = dummy2;
    while (dummy->next)
    {
        dummy = dummy->next;
    }
    dummy->next = temp;
    return ans->next;
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
    head = reverseBetween(head, 2, 4);
    print(head);
    cout << endl;
    return 0;
}