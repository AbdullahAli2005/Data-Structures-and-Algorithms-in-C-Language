#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct node* root, int key) {
    struct node* prev = NULL;
    while (root != NULL) {
        prev = root;
        if (key == root->data) {
            printf("Cannot insert %d, already in BST\n", key);
            return;
        } else if (key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    struct node* newNode = createNode(key);
    if (key < prev->data) {
        prev->left = newNode;
    } else {
        prev->right = newNode;
    }
}

// Function to find the in-order successor (smallest in the right subtree)
struct node* inOrderSuccessor(struct node* root) {
    struct node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root; // Base case: empty tree
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key); // Traverse left subtree
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key); // Traverse right subtree
    } else {
        // Node to be deleted found
        if (root->left == NULL) {
            // Node with only right child or no child
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            // Node with only left child
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the in-order successor
        struct node* temp = inOrderSuccessor(root->right);
        root->data = temp->data; // Copy the in-order successor's content
        root->right = deleteNode(root->right, temp->data); // Delete the in-order successor
    }
    return root;
}

// Function to print the tree in in-order
void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    // Creating the root of the BST
    struct node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    // The tree looks like this:
    //      10
    //     / \
    //    5   15
    //   / \
    //  3   7

    // Displaying the BST in in-order
    printf("In-order traversal before insertion: ");
    inOrder(root);
    printf("\n");

    // Insert new keys
    insert(root, 12);
    insert(root, 20);
    insert(root, 8);

    printf("In-order traversal after insertion: ");
    inOrder(root);
    printf("\n");

    // Delete a node
    root = deleteNode(root, 15);

    printf("In-order traversal after deletion: ");
    inOrder(root);
    printf("\n");

    return 0;
}
