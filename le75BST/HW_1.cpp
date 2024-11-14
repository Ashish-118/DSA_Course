#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

Node *createBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data)
        root->left = createBST(root->left, data);
    else
        root->right = createBST(root->right, data);

    return root;
}

void takeInput(Node *&root)
{

    int d;
    cin >> d;
    while (d != -1)
    {
        root = createBST(root, d);

        cin >> d;
    }
}

int InorderPrecessor(Node *root, int d)
{
    if (root == NULL)
    {
        return -1;
    }

    int l = InorderTraversal(root->left); //  L
    if (root->data == d)
    {
        }

    int r = InorderTraversal(root->right); //  R
}

int main()
{

    Node *root = NULL;

    takeInput(root);

    levelOrderTraversals(root);
    return 0;
}