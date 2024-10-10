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

pair<int, int> Diameter_of_tree(Node *root)
{

    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = Diameter_of_tree(root->left);
    pair<int, int> right = Diameter_of_tree(root->right);
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
int main()
{
    Node *root = NULL;
    root = buildTree();

    // vector<int> possible_diameter;
    // diameter(root, possible_diameter);
    // cout << "Diameter of the tree is " << *max_element(possible_diameter.begin(), possible_diameter.end()) << endl;

    // method 2

    cout << "Diameter of the tree is " << Diameter_of_tree(root).first << endl;

    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1