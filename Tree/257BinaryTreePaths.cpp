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
class Solution
{
public:
    void solve(TreeNode *root, vector<vector<int>> &ans, vector<int> &temp)
    {
        if (root == nullptr)
            return;
        else if (root->left == nullptr && root->right == nullptr)
        {
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
        }

        temp.push_back(root->val);

        solve(root->left, ans, temp);
        solve(root->right, ans, temp);

        temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(root, ans, temp);

        vector<string> result;

        for (auto a : ans)
        {
            string s = "";

            for (auto x : a)
            {
                s += to_string(x) + "->";
            }
            s.pop_back();
            s.pop_back();
            result.push_back(s);
        }

        return result;
    }
};