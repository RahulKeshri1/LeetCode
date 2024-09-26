/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 
Return the linked list sorted as well.

 

Example 1:

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:

Input: head = [1,1,1,2,3]
Output: [2,3]

Constraints:

    The number of nodes in the list is in the range [0, 300].
    -100 <= Node.val <= 100
    The list is guaranteed to be sorted in ascending order.


*/

#include <iostream>
#include <map>
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
    void deleteDuplicate();
    ListNode* returnHead()
    {
        return head;
    }
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

// ListNode* deleteDuplicates(ListNode* head)
void linkedlist::deleteDuplicate()
{
    map<int, int> ma;
    ListNode *temp = head;
    linkedlist dummy;
    while (temp)
    {
        ma[temp->val]++;
        temp = temp->next;
    }
    for(auto pair:ma)
    {
        if(pair.second==1)
        {
            dummy.InsertAtTail(pair.first);
        }
    }
    head=dummy.returnHead();
    //return dummy.returnHead();

}

int main()
{
    linkedlist l;
    l.InsertAtTail(10);
    l.InsertAtTail(20);
    l.InsertAtTail(30);
    l.InsertAtTail(10);
    l.InsertAtTail(40);
    l.InsertAtTail(50);
    l.Print();
    l.deleteDuplicate();
    l.Print();
    return 0;
}