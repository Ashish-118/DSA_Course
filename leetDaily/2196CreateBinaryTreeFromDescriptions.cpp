/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    unordered_map<int, list<pair<int, int>>> adj;
    TreeNode *build(int node)
    {

        TreeNode *temp = new TreeNode(node);

        for (auto x : adj[node])
        {
            if (x.second == 1)
            {
                temp->left = build(x.first);
            }
            else
            {
                temp->right = build(x.first);
            }
        }

        return temp;
    }
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {

        unordered_set<int> allNode;

        for (auto x : descriptions)
        {
            allNode.insert(x[1]);
            adj[x[0]].push_back({x[1], x[2]});
        }

        int initialNode = -1;

        for (auto x : descriptions)
        {
            if (allNode.find(x[0]) == allNode.end())
            {
                initialNode = x[0];
                break;
            }
        }

        return build(initialNode);
    }
};