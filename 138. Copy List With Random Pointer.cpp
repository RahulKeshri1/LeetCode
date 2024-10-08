/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

    val: an integer representing Node.val
    random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.

Your code will only be given the head of the original linked list.



Example 1:

Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:

Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:

Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]



Constraints:

    0 <= n <= 1000
    -104 <= Node.val <= 104
    Node.random is null or is pointing to some node in the linked list.
*/

#include <iostream>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int x)
    {
        this->val = x;
        this->next = NULL;
        this->random = NULL;
    }
};

void Print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << "temp->val= " << temp->val;
        if (temp->random == NULL)
        {
            cout << " temp->random->val= NULL" << endl;
        }
        else
        {
            cout << " temp->random->val= " << temp->random->val << endl;
        }
        temp = temp->next;
    }
    // cout << temp->val<<endl;
}

Node *insert(Node *&head, int x)
{
    Node *newnode = new Node(x);
    if (head == NULL)
    {
        head = newnode;
        return newnode;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return newnode;
}

Node *copyRandomList(Node *head)
{
    if (!head)
        return nullptr;

    // Step 1: Create a deep copy of the list without handling random pointers yet
    Node *temp = head;
    Node *dummy = new Node(0);
    Node *ans = dummy;
    unordered_map<Node *, Node *> nodeMap; // To map original nodes to their copies

    while (temp)
    {
        Node *newnode = new Node(temp->val);
        dummy->next = newnode;
        nodeMap[temp] = newnode; // Store the mapping from original to copied node
        dummy = dummy->next;
        temp = temp->next;
    }

    // Step 2: Handle the random pointers using the map
    temp = head;
    dummy = ans->next; // Point to the head of the copied list

    while (temp)
    {
        if (temp->random)
        {
            dummy->random = nodeMap[temp->random]; // Set the correct random pointer
        }
        temp = temp->next;
        dummy = dummy->next;
    }

    return ans->next; // Return the deep copied list
}

int main()
{
    Node *head = NULL;
    Node *n1, *n2, *n3, *n4, *n5;
    n1 = insert(head, 1);
    n2 = insert(head, 2);
    n3 = insert(head, 3);
    n4 = insert(head, 4);
    n5 = insert(head, 5);
    n1->random = NULL;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;
    Print(head);

    Node *ans = copyRandomList(head);
    Print(ans);
    return 0;
}