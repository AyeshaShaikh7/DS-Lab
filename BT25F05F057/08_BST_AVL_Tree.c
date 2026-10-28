
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *newNode =
        (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* BST insertion */
struct node *bstInsert(struct node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = bstInsert(root->left, data);
    else if (data > root->data)
        root->right = bstInsert(root->right, data);

    return root;
}

/* AVL helper functions */
int height(struct node *root)
{
    return (root == NULL) ? 0 : root->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getBalance(struct node *root)
{
    if (root == NULL)
        return 0;

    return height(root->left) - height(root->right);
}

/* Right rotation */
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

/* Left rotation */
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

/* AVL insertion */
struct node *avlInsert(struct node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = avlInsert(root->left, data);
    else if (data > root->data)
        root->right = avlInsert(root->right, data);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    /* LL case */
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    /* RR case */
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    /* LR case */
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    /* RL case */
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

/* Traversal methods */
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(void)
{
    struct node *bstRoot = NULL;
    struct node *avlRoot = NULL;
    int n, i, data;

    printf("Enter number of elements: ");

    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        if (scanf("%d", &data) != 1)
        {
            printf("Invalid input.\n");
            return 1;
        }

        bstRoot = bstInsert(bstRoot, data);
        avlRoot = avlInsert(avlRoot, data);
    }

    printf("\nBST Traversals:\n");
    printf("Inorder: ");
    inorder(bstRoot);

    printf("\nPreorder: ");
    preorder(bstRoot);

    printf("\nPostorder: ");
    postorder(bstRoot);

    printf("\n\nAVL Tree Traversals:\n");
    printf("Inorder: ");
    inorder(avlRoot);

    printf("\nPreorder: ");
    preorder(avlRoot);

    printf("\nPostorder: ");
    postorder(avlRoot);

    printf("\n");

    return 0;
}
