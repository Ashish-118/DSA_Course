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
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter the data " << endl;
    int d;
    cin >> d;
    root = new Node(d);
    if (d == -1)
    {
        return NULL;
    }

    cout << "Enter the data for inserting in left of " << d << endl;
    root->left = buildTree(root);
    cout << "Enter the data for inserting in right of " << d << endl;
    root->right = buildTree(root);
    return root;
}

// void levelOrderTraversals(Node *root)
// {
//     queue<Node *> q;
//     q.push(root);
//     q.push(NULL);

//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         q.pop();

//         if (temp == NULL)
//         {
//             cout << endl;
//             if (!q.empty())
//             {
//                 q.push(NULL);
//             }
//         }
//         else
//         {
//             cout << temp->data << " ";
//             if (temp->left)
//             {
//                 q.push(temp->left);
//             }
//             if (temp->right)
//             {
//                 q.push(temp->right);
//             }
//         }
//     }
// }

// void InorderTraversal(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     InorderTraversal(root->left);  //  L
//     cout << root->data << " ";     //  N
//     InorderTraversal(root->right); //  R
// }
// void PreorderTraversal(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     cout << root->data << " ";      //  N
//     PreorderTraversal(root->left);  //  L
//     PreorderTraversal(root->right); //  R
// }
// void PostorderTraversal(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     PostorderTraversal(root->left);  //  L
//     PostorderTraversal(root->right); //  R
//     cout << root->data << " ";       //  N
// }

// void buildFromLevelOrder(Node *&root)
// {
//     queue<Node *> q;
//     cout << "Enter the data for root: " << endl;
//     int data;
//     cin >> data;
//     root = new Node(data);
//     q.push(root);

//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         q.pop();

//         cout << "Enter the left child of " << temp->data << ": " << endl;
//         int leftData;
//         cin >> leftData;
//         if (leftData != -1)
//         {
//             temp->left = new Node(leftData);
//             q.push(temp->left);
//         }

//         cout << "Enter the right child of " << temp->data << ": " << endl;
//         int rightData;
//         cin >> rightData;
//         if (rightData != -1)
//         {
//             temp->right = new Node(rightData);
//             q.push(temp->right);
//         }
//     }
// }

void morrisTraversal(Node *root)
{
    Node *current = root;
    while (root != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data;
            current = current->right;
        }
        else
        {
            // Node *predecessor=
            Node
        }
    }
}

int main()
{
    Node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);
    // // levelOrderTraversals(root);
    // cout << "\nthis is inorder Traversal" << endl;
    // InorderTraversal(root);
    // cout << "\nthis is Pre order Traversal" << endl;
    // PreorderTraversal(root);
    // cout << "\nthis is Post order Traversal" << endl;
    // PostorderTraversal(root);

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);

    return 0;
}