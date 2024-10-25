/*
You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.

Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.



Example 1:

Input: head = [0,1,2,3], nums = [0,1,3]
Output: 2
Explanation: 0 and 1 are connected, so [0, 1] and [3] are the two connected components.

Example 2:

Input: head = [0,1,2,3,4], nums = [0,3,1,4]
Output: 2
Explanation: 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.



Constraints:

    The number of nodes in the linked list is n.
    1 <= n <= 104
    0 <= Node.val < n
    All the values Node.val are unique.
    1 <= nums.length <= n
    0 <= nums[i] < n
    All the values of nums are unique.


*/

#include <iostream>
#include <unordered_set>
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

int numComponents(ListNode *head, vector<int> &nums)
{
    unordered_set<int> numSet(nums.begin(), nums.end()); // Store nums in a set for fast lookup
    int components = 0;                                  // Count the number of components
    bool inComponent = false;                            // Track if we are in a connected component

    // Traverse the linked list
    while (head)
    {
        // If current node's value is in the set and we are not already in a component
        if (numSet.count(head->val) > 0)
        {
            if (!inComponent)
            {
                components++; // Start a new component
                inComponent = true;
            }
        }
        else
        {
            inComponent = false; // End the current component
        }
        head = head->next; // Move to the next node
    }

    return components; // Return the number of connected components
}
int main()
{
    ListNode *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    vector<int> nums = {1, 2, 5};

    cout << numComponents(head, nums) << endl;
    return 0;
}