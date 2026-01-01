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
    void solve(TreeNode *root, string &s, vector<string> &ans)
    {
        if (!root)
            return;
        else if (!root->left && !root->right)
        {
            s += ('a' + root->val);
            ans.push_back(s);
            s.pop_back();
            return;
        }

        s += ('a' + root->val);
        solve(root->left, s, ans);
        solve(root->right, s, ans);
        s.pop_back();
    }
    string smallestFromLeaf(TreeNode *root)
    {
        string s = "";
        vector<string> ans;

        solve(root, s, ans);
        string ret = "{";

        for (auto a : ans)
        {
            reverse(begin(a), end(a));
            ret = min(ret, a);
        }

        return ret;
    }
};