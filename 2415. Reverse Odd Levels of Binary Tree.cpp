/*
2415. Reverse Odd Levels of Binary Tree

Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

    For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].

Return the root of the reversed tree.

A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

The level of a node is the number of edges along the path between it and the root node.

 

Example 1:

Input: root = [2,3,5,8,13,21,34]
Output: [2,5,3,8,13,21,34]
Explanation: 
The tree has only one odd level.
The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.

Example 2:

Input: root = [7,13,11]
Output: [7,11,13]
Explanation: 
The nodes at level 1 are 13, 11, which are reversed and become 11, 13.

Example 3:

Input: root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
Output: [0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
Explanation: 
The odd levels have non-zero values.
The nodes at level 1 were 1, 2, and are 2, 1 after the reversal.
The nodes at level 3 were 1, 1, 1, 1, 2, 2, 2, 2, and are 2, 2, 2, 2, 1, 1, 1, 1 after the reversal.

 

Constraints:

    The number of nodes in the tree is in the range [1, 214].
    0 <= Node.val <= 105
    root is a perfect binary tree.


*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if (!root)
            return nullptr;

        queue<TreeNode *> q;
        q.push(root);
        bool isOddLevel = false;

        while (!q.empty())
        {
            int levelSize = q.size();
            vector<TreeNode *> currentLevelNodes;

            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode *node = q.front();
                q.pop();

                currentLevelNodes.push_back(node);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (isOddLevel)
            {
                reverse(currentLevelNodes.begin(), currentLevelNodes.end());
            }

            isOddLevel = !isOddLevel;
        }

        return root;
    }
};

int main()
{
    // Example usage
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    root = sol.reverseOddLevels(root);

    // Add your code to print the tree and check the result

    // Cleanup memory (delete only once to avoid double free)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
