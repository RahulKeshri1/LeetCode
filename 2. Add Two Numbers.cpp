/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]



Constraints:

    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.


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
        val = data; // Corrected initialization
        next = NULL;
    }
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode(0);
    ListNode *head = ans;
    int digit = 0;
    int carry = 0;
    while (l1 && l2)
    {
        digit = (l1->val + l2->val + carry) % 10;
        ListNode *newnode = new ListNode(digit);

        ans->next = newnode;
        ans = ans->next;
        carry = (l1->val + l2->val + carry) / 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1)
    {
        digit = (l1->val + carry) % 10;
        ListNode *newnode = new ListNode(digit);
        ans->next = newnode;
        ans = ans->next;
        carry = (l1->val + carry) / 10;
        l1 = l1->next;
    }
    while (l2)
    {
        digit = (l2->val + carry) % 10;
        ListNode *newnode = new ListNode(digit);
        ans->next = newnode;
        ans = ans->next;
        carry = (l2->val + carry) / 10;
        l2 = l2->next;
    }
    if (carry > 0)
    {
        ListNode *newnode = new ListNode(carry);
        ans->next = newnode;
    }
    return head->next;
}

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
    while (head != NULL)
    {
        cout << head->val;
        if (head->next != NULL)
        {
            cout << "-> ";
        }
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;
    ListNode *head = NULL;

    push(head1, 2);
    push(head1, 4);
    push(head1, 3);

    push(head2, 5);
    push(head2, 6);
    push(head2, 4);

    head = addTwoNumbers(head1, head2);
    print(head);

    return 0;
}
