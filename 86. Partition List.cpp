/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:

Input: head = [2,1], x = 2
Output: [1,2]

 

Constraints:

    The number of nodes in the list is in the range [0, 200].
    -100 <= Node.val <= 100
    -200 <= x <= 200
*/

#include <iostream>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode()
    {
        this->val = 0;
        this->next = NULL;
    }
    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

class linkedlist
{
private:
    ListNode *head = NULL;

public:
    // Printint the Linkedlist
    void Print();

    // Insertion Operations
    void InsertAtTail(int);
    void partition(int);
};

void linkedlist::Print()
{
    ListNode *temp = head;
    if (head == NULL)
    {
        cout << "The list is empty!!" << endl;
        return;
    }
    else
    {
        while (temp->next != NULL)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << temp->val << endl;
    }
}

void linkedlist::InsertAtTail(int x)
{
    ListNode *temp = new ListNode;
    ListNode *n = new ListNode(x);
    temp = head;
    if (head == NULL)
    {
        head = n;
        return;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void linkedlist::partition(int x)
// ListNode* partition(ListNode* head, int x)
{
    ListNode *dummy = new ListNode(0);
    ListNode *ans = dummy;
    ListNode *temp = head;
    while (temp)
    {
        if (temp->val < x)
        {
            ListNode *newnode = new ListNode(temp->val);
            dummy->next = newnode;
            dummy = newnode;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        if (temp->val >= x)
        {
            ListNode *newnode = new ListNode(temp->val);
            dummy->next = newnode;
            dummy = newnode;
        }
        temp = temp->next;
    }
    head = ans->next;
    // return ans->next;
}

int main()
{
    linkedlist l;
    l.InsertAtTail(10);
    l.InsertAtTail(20);
    l.InsertAtTail(50);
    l.InsertAtTail(30);
    l.InsertAtTail(10);
    l.InsertAtTail(40);
    l.InsertAtTail(50);
    l.Print();
    l.partition(30);
    l.Print();
    return 0;
}