/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.



Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]



Constraints:

    The number of nodes in the list is n.
    1 <= k <= n <= 5000
    0 <= Node.val <= 1000

*/

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

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == nullptr || k == 1)
    {
        return head;
    }

    // Count the number of nodes in the linked list
    int size = 0;
    ListNode *temp = head;
    while (temp)
    {
        size++;
        temp = temp->next;
    }

    // Dummy node to manage connections and the new head of the reversed list
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *prevGroupEnd = dummy; // Keeps track of the last node of the previous reversed group
    ListNode *curr = head;

    for (int i = 0; i < size / k; i++)
    {
        ListNode *groupStart = curr;
        ListNode *groupEnd = curr;
        ListNode *nextNode = nullptr;

        // Move groupEnd to the last node of the current group
        for (int j = 1; j < k; j++)
        {
            groupEnd = groupEnd->next;
        }

        // Save the node after the group to reattach it later
        nextNode = groupEnd->next;

        // Reverse the nodes within the group
        ListNode *prev = nextNode;
        while (curr != nextNode)
        {
            ListNode *tempNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tempNext;
        }

        // Reconnect the reversed group back to the rest of the list
        prevGroupEnd->next = groupEnd;
        prevGroupEnd = groupStart;
    }

    return dummy->next;
}

int main()
{
    ListNode *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    head = reverseKGroup(head, 2);
    Print(head);
    return 0;
}