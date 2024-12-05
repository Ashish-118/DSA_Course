#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d)
    {
        this->val = d;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *buildTree(TreeNode *root)
{
    cout << "Enter the data " << endl;
    int d;
    cin >> d;
    root = new TreeNode(d);
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

class Solution
{
public:
    void levelOrderTraversals(TreeNode *root, vector<vector<int>> &data)
    {
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            vector<int> t;
            TreeNode *temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                cout << endl;
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                t.push_back(temp->val);

                if (temp->left)
                {
                    q.push(temp->left);
                    t.push_back(temp->left->val);
                }
                else
                {
                    t.push_back(-1);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                    t.push_back(temp->right->val);
                }
                else
                {
                    t.push_back(-1);
                }
                data.push_back(t);
            }
        }
    }

    void solve(int &count, queue<int> p, vector<vector<int>> data, map<int, bool> visited)
    {
        while (!p.empty())
        {

            int front = p.front();

            p.pop();

            if (front == -1)
            {
                if (!p.empty())
                {
                    p.push(-1);
                    count++;
                }
            }
            else
            {
                visited[front] = true;
                for (int i = 0; i < data.size(); i++)
                {

                    if (data[i][0] == front)
                    {
                        if (data[i][1] != -1 && visited[data[i][1]] == false)
                            p.push(data[i][1]);
                        if (data[i][2] != -1 && visited[data[i][2]] == false)
                            p.push(data[i][2]);
                        break;
                    }
                    else
                    {
                        if (!visited[data[i][0]])
                        {
                            for (int j = 1; j < 3; j++)
                            {
                                if (data[i][j] == front)
                                {
                                    p.push(data[i][0]);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int amountOfTime(TreeNode *root, int start)
    {
        vector<vector<int>> traversed_data;
        levelOrderTraversals(root, traversed_data);
        int count = 0;
        map<int, bool> pathVisited;
        for (int i = 0; i < traversed_data.size(); i++)
        {
            pathVisited[traversed_data[i][0]] = false;
        }
        queue<int> p;
        p.push(start);
        p.push(-1);

        solve(count, p, traversed_data, pathVisited);
        return count;
    }
};
int main()
{
    TreeNode *root = NULL;
    // 1 5 - 1 4 9 - 1 - 1 2 - 1 - 1 3 10 - 1 - 1 6 - 1 - 1
    root = buildTree(root);
    Solution s;
    cout << s.amountOfTime(root, 5) << endl;
    return 0;
}