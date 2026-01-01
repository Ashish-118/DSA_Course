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
    pair<int, int> solve(TreeNode *root, int &ans)
    {
        if (root == nullptr)
            return {-1, -1};

        pair<int, int> left = solve(root->left, ans);
        pair<int, int> right = solve(root->right, ans);

        int maxi = root->val;
        int mini = root->val;

        if (left.first != -1)
        {
            mini = min(mini, left.first);
            maxi = max(maxi, left.second);
            ans = max({ans, abs(root->val - left.first),
                       abs(root->val - left.second)});
        }
        if (right.first != -1)
        {
            mini = min(mini, right.first);
            maxi = max(maxi, right.second);
            ans = max({ans, abs(root->val - right.first),
                       abs(root->val - right.second)});
        }

        return {mini, maxi};
    }

    int maxAncestorDiff(TreeNode *root)
    {

        int ans = 0;
        solve(root, ans);
        return ans;
    }
};

// most optimal approach

class Solution
{
public:
    int findMaxDiff(TreeNode *root, int minV, int maxV)
    {
        if (!root)
            return abs(minV - maxV);

        minV = min(root->val, minV);
        maxV = max(root->val, maxV);

        int l = findMaxDiff(root->left, minV, maxV);
        int r = findMaxDiff(root->right, minV, maxV);

        return max(l, r);
    }

    int maxAncestorDiff(TreeNode *root)
    {
        int minV = root->val;
        int maxV = root->val;

        return findMaxDiff(root, minV, maxV);
    }
};
