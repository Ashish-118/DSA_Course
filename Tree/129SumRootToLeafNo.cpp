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
    void solve(TreeNode *root, string &num, int &ans)
    {
        if (!root)
            return;
        else if (!root->left && !root->right)
        {
            num += to_string(root->val);
            ans += stoi(num);
            num.pop_back();

            return;
        }

        num += to_string(root->val);
        solve(root->left, num, ans);
        solve(root->right, num, ans);
        num.pop_back();
    }
    int sumNumbers(TreeNode *root)
    {
        int ans = 0;
        string num = "";
        solve(root, num, ans);
        return ans;
    }
};