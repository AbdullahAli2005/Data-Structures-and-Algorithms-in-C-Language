#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Check if the tree is a BST
int isBSTUtil(struct node *root, struct node **prev)
{
    if (root != NULL)
    {
        if (!isBSTUtil(root->left, prev))
        {
            return 0;
        }
        if (*prev != NULL && root->data <= (*prev)->data)
        {
            return 0;
        }
        *prev = root;
        return isBSTUtil(root->right, prev);
    }
    return 1;
}

int isBST(struct node *root)
{
    struct node *prev = NULL;
    return isBSTUtil(root, &prev);
}

struct node *searchIter(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            printf("Element %d found in the tree.\n", key);
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    printf("Element %d not found in the tree.\n", key);
    return NULL;
}

int main()
{
    struct node *root = createNode(10);
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

    if (isBST(root))
    {
        printf("The tree is a BST.\n");
    }
    else
    {
        printf("The tree is not a BST.\n");
    }

    struct node *search = searchIter(root, 7);

    return 0;
}
