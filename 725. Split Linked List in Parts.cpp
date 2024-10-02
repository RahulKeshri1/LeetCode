/*
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

 

Example 1:

Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

Example 2:

Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.

 

Constraints:

    The number of nodes in the list is in the range [0, 1000].
    0 <= Node.val <= 1000
    1 <= k <= 50
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
    // ListNode()
    // {
    //     this
    //     this->next=NULL;
    // }
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

vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    int size = 0;           // Variable to count the total number of nodes
    ListNode *temp = head;  // Pointer to traverse the linked list
    vector<ListNode *> ans; // Vector to store the heads of the resulting parts

    // First loop to count the number of nodes in the linked list
    while (temp)
    {
        size++;            // Increment the size for each node
        temp = temp->next; // Move to the next node
    }

    temp = head; // Reset temp to point to the head of the linked list

    // Handle the case when the number of nodes is less than or equal to k
    if (size <= k)
    {
        while (k--)
        {
            if (temp != NULL)
            {
                // Create a new ListNode for the current node's value
                ListNode *temp1 = new ListNode(temp->val);
                ans.push_back(temp1); // Add the new node to the result vector
                temp = temp->next;    // Move to the next node in the original list
            }
            else
            {
                // If there are no more nodes, push NULL into the vector
                ans.push_back(NULL);
            }
        }
        return ans; // Return the resulting parts
    }

    // Calculate the size of each part
    int set = size / k;   // Minimum number of nodes in each part
    int extra = size % k; // Number of parts that will get an extra node
    int counter = 0;      // Counter for the parts created

    // Loop to create each part of the linked list
    while (temp)
    {
        ListNode *sub = new ListNode(0); // Dummy head for the current part
        ListNode *first = sub;           // Pointer to build the current part
        int t = set;                     // Initialize the count of nodes for this part

        // If there are extra nodes left, add one more to this part
        if (extra)
        {
            t++;
            extra--; // Decrement the extra counter
        }

        // Create the nodes for the current part
        for (int i = 0; i < t; i++)
        {
            ListNode *temp2 = new ListNode(temp->val); // Create a new node
            sub->next = temp2;                         // Link it to the current part
            sub = temp2;                               // Move to the newly created node
            temp = temp->next;                         // Move to the next node in the original list
            // Note: No need to delete temp2; it's added to the list
        }

        ans.push_back(first->next); // Add the current part to the result vector
    }

    return ans; // Return the vector containing the k parts
}

int main()
{
    ListNode *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    insert(head, 8);
    insert(head, 9);
    insert(head, 10);

    vector<ListNode *> ans = splitListToParts(head, 3);
    cout << ans.size();
    for (int i = 0; i < ans.size(); i++)
    {
        Print(ans[i]);
        // cout<<ans[i]->val;
    }
    cout << endl;
    return 0;
}