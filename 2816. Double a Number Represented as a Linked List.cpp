/*
You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.

 

Example 1:

Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.

Example 2:

Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998. 

 

Constraints:

    The number of nodes in the list is in the range [1, 10^4]
    0 <= Node.val <= 9
    The input is generated such that the list represents a number that does not have leading zeros, except the number 0 itself.
*/

#include <iostream>
#include <stack>
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
        cout << temp->val;
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

ListNode *doubleIt(ListNode *head)
{
    stack<int> st;
    ListNode *temp = head;
    while (temp)
    {
        st.push(temp->val);
        temp = temp->next;
    }
    int carry = 0;
    ListNode *dummy = NULL;
    while (!st.empty())
    {
        int num = st.top();
        st.pop();
        int sum = carry + (num * 2);
        int digit = sum % 10;
        carry = sum / 10;
        ListNode *newnode = new ListNode(digit);
        newnode->next = dummy;
        dummy = newnode;
    }
    if (carry > 0)
    {
        ListNode *newnode = new ListNode(carry);
        newnode->next = dummy;
        dummy = newnode;
    }
    return dummy;
}

int main()
{
    ListNode *head = NULL;
    insert(head, 9);
    insert(head, 9);
    insert(head, 9);
    cout<<"Before doubling:\t";
    Print(head);
    cout<<"After doubling:\t\t";
    Print( doubleIt(head));
    return 0;
}