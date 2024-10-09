#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to remove leaf nodes whose value is equal to the target
TreeNode* removeLeafNodes(TreeNode* root, int target) 
{
    // Base case: if root is NULL, return NULL
    if (root == NULL) {
        return NULL;
    }

    // Recursively remove leaf nodes from left and right subtrees
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    // After recursion, check if the current node is a leaf and matches the target
    if (root->left == NULL && root->right == NULL && root->val == target) {
        return NULL;  // This node is a leaf and should be deleted
    }

    // Return the (potentially modified) root
    return root;
}

// Helper function to print the tree in in-order traversal
void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Helper function to delete the tree
void deleteTree(TreeNode* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Create a sample binary tree
    /*
            1
           / \
          2   3
         /   / \
        2   2   4
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);

    // Define the target value to remove from leaf nodes
    int target = 2;

    // Print the tree before removal
    cout << "In-order traversal before removing leaf nodes with value " << target << ": ";
    inorderTraversal(root);
    cout << endl;

    // Remove leaf nodes with the target value
    root = removeLeafNodes(root, target);

    // Print the tree after removal
    cout << "In-order traversal after removing leaf nodes with value " << target << ": ";
    inorderTraversal(root);
    cout << endl;

    // Clean up the tree
    deleteTree(root);

    return 0;
}
