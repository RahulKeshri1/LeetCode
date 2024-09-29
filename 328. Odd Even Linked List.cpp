/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

 

Constraints:

    The number of nodes in the linked list is in the range [0, 104].
    -106 <= Node.val <= 106
*/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int val)
    {
        data = val;
        next = NULL;
    }
};

ListNode *oddEvenList(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = even; // We need to keep the start of the even list

    while (even && even->next)
    {
        odd->next = even->next; // Link odd nodes together
        odd = odd->next;        // Move the odd pointer
        even->next = odd->next; // Link even nodes together
        even = even->next;      // Move the even pointer
    }

    odd->next = evenHead; // Join odd and even lists
    return head;
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
    while (head->next != NULL)
    {
        cout << head->data << "-> ";
        head = head->next;
    }
    cout << head->data;
}

int main()
{
    ListNode *head = NULL;
    for (int i = 1; i <= 10; i++)
    {
        push(head, i);
    }

    print(head);
    cout << endl;
    head = oddEvenList(head);
    print(head);
    cout << endl;
    return 0;
}