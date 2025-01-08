#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}  // Initialize with 0 and nullptr
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to print the linked list
void Print(ListNode *head)
{
    if (head == nullptr)
    {
        cout << "The list is empty!!" << endl;
        return;
    }
    else
    {
        ListNode *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val;
            if (temp->next != nullptr)
                cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
}

// Function to insert a node at the tail of the list
void InsertAtTail(ListNode *&head, int x)  // Pass head by reference
{
    ListNode *n = new ListNode(x);
    if (head == nullptr)
    {
        head = n;
        return;
    }
    ListNode *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = n;
}

// Function to merge k sorted linked lists
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.empty()) return nullptr;

    vector<int> temp;
    for (ListNode *list : lists)
    {
        ListNode *node = list;
        while (node)
        {
            temp.push_back(node->val);
            node = node->next;
        }
    }

    sort(temp.begin(), temp.end());

    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;
    for (int val : temp)
    {
        current->next = new ListNode(val);
        current = current->next;
    }

    return dummy->next;
}

int main()
{
    ListNode *l1 = nullptr;  // Initialize pointers to nullptr
    ListNode *l2 = nullptr;
    ListNode *l3 = nullptr;

    InsertAtTail(l1, 10);
    InsertAtTail(l1, 20);
    InsertAtTail(l1, 30);

    InsertAtTail(l2, 1);
    InsertAtTail(l2, 2);

    InsertAtTail(l3, 3);
    InsertAtTail(l3, 2);
    InsertAtTail(l3, 6);

    vector<ListNode *> lists = {l1, l2, l3};
    ListNode *mergedList = mergeKLists(lists);
    Print(mergedList);

    return 0;
}