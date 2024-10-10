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

void leftPart(Node *root)
{

    while ((root != NULL) && (root->left != NULL || root->right != NULL))
    {
        cout << root->data << " " << endl;
        if (root->left)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
}
void rightPart(Node *root)
{

    while ((root != NULL) && (root->left != NULL || root->right != NULL))
    {
        cout << root->data << " " << endl;
        if (root->right)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
}
// void rightPart_recurssion(Node *root)
// {
//     if ((root == NULL) || (root->left == NULL && root->right == NULL))
//         return;
//     cout << root->data << " " << endl;
//     if (root->left)
//         rightPart_recurssion(root->left);
//     else
//         rightPart_recurssion(root->right);
// }

// void traverseRight(Node *root, vector<int> &ans)
// {
//     // base case
//     if ((root == NULL) || (root->left = NULL &&root->right = NULL))
//         return;
//     if (root->right)
//         traverseRight(root->right, ans);
//     else
//         traverseLeft(root->left, ans);
//     // wapas aagye
//     ans.push_back(root->data);
// }
void getLeaf(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        cout << root->data << " ";
    getLeaf(root->left);
    getLeaf(root->right);
}
int main()
{
    Node *root = NULL;
    root = buildTree();

    leftPart(root->left);
    rightPart(root->right);
    // rightPart_recurssion(root->right);
    getLeaf(root);

    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
