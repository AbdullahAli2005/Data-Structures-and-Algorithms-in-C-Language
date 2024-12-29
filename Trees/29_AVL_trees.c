#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;               
    struct Node *left;     
    struct Node *right;    
    int height;          
};

// Function to get the height of a node
int getHeight(struct Node *node) {
    if (node == NULL)      
        return 0;
    return node->height;
}

// Utility function to create a new node
struct Node *createNode(int key) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;   // New nodes are always added as leaves with height 1
    return newNode;
}

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to calculate the balance factor of a node
// Formula:
// Balance Factor = Height of left subtree - Height of right subtree
int getBalanceFactor(struct Node *node) {
    if (node == NULL)      
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to perform a right rotation
// Example: Left-Left (LL) Case (Left-heavy tree)
// Before Rotation (Unbalanced at 5):
//        5
//       /
//      3
//     / \ 
//    2   NULL
//
// After Right Rotation:
//        3
//       / \
//      2   5
//         / 
//       NULL
// 
// Explanation:
// The unbalanced node is 5. Its left child (3) becomes the new root of the subtree.
// The right child of 3 (if any, here NULL) becomes the left child of 5.
struct Node *rightRotate(struct Node *unbalancedNode) {
    struct Node *leftChild = unbalancedNode->left; 
    struct Node *leftRightSubtree = leftChild->right;

    // Perform rotation
    leftChild->right = unbalancedNode;
    unbalancedNode->left = leftRightSubtree;

    // Update heights
    unbalancedNode->height = max(getHeight(unbalancedNode->left), getHeight(unbalancedNode->right)) + 1;
    leftChild->height = max(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;

    // Return the new root after rotation
    return leftChild;
}

// Function to perform a left rotation
// Example: Right-Right (RR) Case (Right-heavy tree)
// Before Rotation (Unbalanced at 3):
//      3
//       \
//        5
//       / \
//      4   6
//
// After Left Rotation:
//      5
//     / \
//    3   6
//     \
//      4
//
// Explanation:
// The unbalanced node is 3. Its right child (5) becomes the new root of the subtree.
// The left child of 5 (node 4) becomes the right child of 3.
struct Node *leftRotate(struct Node *unbalancedNode) {
    struct Node *rightChild = unbalancedNode->right;
    struct Node *rightLeftSubtree = rightChild->left;

    // Perform rotation
    rightChild->left = unbalancedNode;
    unbalancedNode->right = rightLeftSubtree;

    // Update heights
    unbalancedNode->height = max(getHeight(unbalancedNode->left), getHeight(unbalancedNode->right)) + 1;
    rightChild->height = max(getHeight(rightChild->left), getHeight(rightChild->right)) + 1;

    // Return the new root after rotation
    return rightChild;
}

// Function to insert a node into the AVL tree
struct Node *insert(struct Node *node, int key) {
    // Perform standard BST insertion
    if (node == NULL)      // Base case: Insert the node here
        return createNode(key);

    if (key < node->key)   
        node->left = insert(node->left, key);
    else if (key > node->key) 
        node->right = insert(node->right, key);
    else                 
        return node;   // Duplicate keys are not allowed in BST

    // Update the height of the current node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get the balance factor to check if the node became unbalanced
    int balanceFactor = getBalanceFactor(node);

    // Left-Left (LL) Case
    if (balanceFactor > 1 && key < node->left->key)
        return rightRotate(node);

    // Right-Right (RR) Case
    if (balanceFactor < -1 && key > node->right->key)
        return leftRotate(node);

    // Left-Right (LR) Case
    if (balanceFactor > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right-Left (RL) Case
    if (balanceFactor < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

// Function to perform a pre-order traversal: Root -> Left -> Right
void preOrderTraversal(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);        
        preOrderTraversal(root->left);  
        preOrderTraversal(root->right);  
    }
}

int main() {
    struct Node *root = NULL;

    // Insert nodes into the AVL tree
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    // Print the tree in pre-order traversal
    printf("Pre-order traversal of the AVL tree:\n");
    preOrderTraversal(root);

    return 0;
}

// Output:
//         4
//        / \
//       2   5 
//      / \   \
//     1   3   6