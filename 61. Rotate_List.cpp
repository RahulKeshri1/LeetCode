/*Given the head of a linked list, rotate the list to the right by k places.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:

Input: head = [0,1,2], k = 4
Output: [2,0,1]

Constraints:

    The number of nodes in the list is in the range [0, 500].
    -100 <= Node.val <= 100
    0 <= k <= 2 * 109
*/

#include <iostream>
#include <vector>

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
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    int size = 0;
    ListNode *temp = head;
    while (temp)
    {
        temp = temp->next;
        size++;
    }
    k = k % size;
    cout << "k= " << k << endl;
    for (int i = 0; i < k; i++)
    {
        ListNode *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        ListNode *first = temp->next;
        temp->next = nullptr;
        first->next = head;
        head = first;
    }
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
    for (int i = 1; i <= 3; i++)
    {
        push(head, i);
    }

    print(head);
    cout << endl;
    head = rotateRight(head, 20000);
    print(head);
    cout << endl;
    return 0;
}