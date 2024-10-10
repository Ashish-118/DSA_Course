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

int noOfLeafNodes(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {

        return 1;
    }

    int left = (root->left != NULL ? noOfLeafNodes(root->left) : 0);
    int right = (root->right != NULL ? noOfLeafNodes(root->right) : 0);

    return left + right;
}

int diameter(Node *root, vector<int> &possible_diameter)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = diameter(root->left, possible_diameter);
    int right = diameter(root->right, possible_diameter);
    possible_diameter.push_back((left + right + 1));
    return (max(left, right) + 1);
}

int main()
{
    Node *root = NULL;
    root = buildTree();

    // int x = height(root);
    // cout << "Height of the tree is: " << x << endl;
    // cout << "No of Leaf nodes in the tree is " << noOfLeafNodes(root) << endl;

    vector<int> possible_diameter;
    diameter(root, possible_diameter);
    cout<<"Diameter of the tree is "<<*max_element(possible_diameter.begin(), possible_diameter.end())<<endl;
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1