/*
Given the head of a singly linked list, return true if it is a
palindrome
or false otherwise.

 

Example 1:

Input: head = [1,2,2,1]
Output: true

Example 2:

Input: head = [1,2]
Output: false

 

Constraints:

    The number of nodes in the list is in the range [1, 105].
    0 <= Node.val <= 9
*/

#include <iostream>
#include <vector>
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

bool isPalindrome(ListNode *head)
{
    ListNode *temp = head;
    vector<int> vec;
    while (temp)
    {
        vec.push_back(temp->val);
        temp = temp->next;
    }
    int size = vec.size();
    int mid = size / 2;
    int j = size - 1;
    for (int i = 0; i < mid; i++)
    {
        if (vec[i] != vec[j])
        {
            return false;
        }
        j--;
    }
    return true;
}
int main()
{
    ListNode *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);

    cout <<isPalindrome(head)<<endl;
    return 0;
}