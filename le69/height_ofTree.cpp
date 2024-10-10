#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree()
{
    cout << "Enter the data (-1 for no node): " << endl;
    int d;
    cin >> d;
    
    if (d == -1)
    {
        return NULL;
    }

    Node *root = new Node(d);

    cout << "Enter the data for inserting in the left of " << d << endl;
    root->left = buildTree();

    cout << "Enter the data for inserting in the right of " << d << endl;
    root->right = buildTree();

    return root;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}



int main()
{
    Node *root = NULL;
    root = buildTree();

    int x = height(root);
    cout << "Height of the tree is: " << x << endl;

    return 0;
}

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1