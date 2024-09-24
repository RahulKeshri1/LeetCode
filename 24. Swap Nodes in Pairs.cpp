/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)


Example 1:

Input: head = [1,2,3,4]

Output: [2,1,4,3]

Explanation:

Example 2:

Input: head = []

Output: []

Example 3:

Input: head = [1]

Output: [1]

Example 4:

Input: head = [1,2,3]

Output: [2,1,3]

 

Constraints:

    The number of nodes in the list is in the range [0, 100].
    0 <= Node.val <= 100


*/


#include <iostream>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode()
    {
        this->data = 0;
        this->next = NULL;
    }
    ListNode(int x)
    {
        this->data = x;
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
    void swapPairs();
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
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data << endl;
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

void linkedlist::swapPairs()
// ListNode* swapPairs(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        // return head; // Return head if the list is empty or has only one node
        return;
    }

    ListNode *newHead = head->next; // New head after swapping
    ListNode *temp = head;          // Pointer for the current node
    ListNode *previous = nullptr;   // Pointer to keep track of the previous pair

    while (temp != nullptr && temp->next != nullptr)
    {
        ListNode *first = temp;        // First node of the pair
        ListNode *second = temp->next; // Second node of the pair

        // Perform the swap
        first->next = second->next; // Point first node to the next of second
        second->next = first;       // Point second node to first node

        // Connect the previous pair to the new pair
        if (previous != nullptr)
        {
            previous->next = second; // Link the last swapped pair to the current
        }

        // Update previous to the first node (now the second node after swap)
        previous = first; // Move previous to the first node (swapped)

        // Move to the next pair
        temp = first->next; // Move temp to the next pair
    }
    head = newHead;
    // return newHead;                         // Return the new head of the swapped list
}

int main()
{
    linkedlist l;
    l.InsertAtTail(10);
    l.InsertAtTail(20);
    l.InsertAtTail(30);
    l.InsertAtTail(40);
    l.InsertAtTail(50);
    l.InsertAtTail(60);
    l.Print();
    l.swapPairs();
    l.Print();
    return 0;
}