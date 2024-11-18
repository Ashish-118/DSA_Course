#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    int height;

    node(int d)
    {
        data = d;
        left = right = nullptr;
        height = 1;
    }
};

int height(node *Node)
{
    if (Node == nullptr)
        return 0;
    return Node->height;
}

int getBalance(node *Node)
{
    return height(Node->left) - height(Node->right);
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *temp = x->right;
    x->right = y;
    y->left = temp;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

node *leftRotate(node *y)
{
    node *x = y->right;
    node *temp = x->left;
    x->left = y;
    y->right = temp;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

node *insert(node *&root, int d)
{
    if (root == nullptr)
    {
        root = new node(d);
        return root;
    }
    if (d < root->data)
    {
        root->left = insert(root->left, d);
    }
    else if (d > root->data)
    {
        root->right = insert(root->right, d);
    }
    else
    {
        return root;
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);

    if (balance > 1 && d < root->left->data)
    {
        return rightRotate(root);
    }
    else if (balance < -1 && d > root->right->data)
    {
        return leftRotate(root);
    }
    else if (balance > 1 && d > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if (balance < -1 && d < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main()
{
    node *root = nullptr;

    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);

    return 0;
}
