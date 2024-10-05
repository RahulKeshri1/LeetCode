/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:

Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]

 

Constraints:

    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.
*/

#include <iostream>
#include<stack>
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
    cout << head->val<<endl;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = NULL;
    stack<int> num1;
    stack<int> num2;
    ListNode *temp1 = l1;
    ListNode *temp2 = l2;
    while (temp1)
    {
        num1.push(temp1->val);
        temp1 = temp1->next;
    }
    while (temp2)
    {
        num2.push(temp2->val);
        temp2 = temp2->next;
    }
    int carry = 0;
    while (!(num1.empty() && num2.empty()))
    {
        int n1 = 0;
        int n2 = 0;
        if (!num1.empty())
        {
            n1 = num1.top();
            num1.pop();
        }
        if (!num2.empty())
        {
            n2 = num2.top();
            num2.pop();
        }
        ListNode *newnode = new ListNode((n1 + n2 + carry) % 10);
        carry = (n1 + n2 + carry) / 10;
        newnode->next = head;
        head = newnode;
    }
    if (carry)
    {
        ListNode *newnode = new ListNode(carry);
        newnode->next = head;
        head = newnode;
    }
    return head;
}

int main()
{
    ListNode *head1 = NULL;
    ListNode*head2=NULL;
    push(head1,7);
    push(head1,2);
    push(head1,4);
    push(head1,3);
    push(head2,5);
    push(head2,6);
    push(head2,4);
    print(head1);
    print(head2);
    cout << endl;
    ListNode*sum = addTwoNumbers(head1,head2);
    cout<<"Sum:- ";
    print(sum);
    cout << endl;
    return 0;
}