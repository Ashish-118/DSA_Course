// Approach-1 (Using 2 Pass Solution and LCA code)
// T.C : O(2*n) ~= O(n)
// S.C : O(maxDepth) System stack space
class Solution
{
public:
    unordered_map<int, int> mp;
    int maxD = 0;

    TreeNode *LCA(TreeNode *root)
    {
        if (root == NULL || mp[root->val] == maxD)
        {
            return root;
        }

        TreeNode *l = LCA(root->left);
        TreeNode *r = LCA(root->right);

        if (l && r)
        {
            return root;
        }

        return l != NULL ? l : r;
    }

    void depth(TreeNode *root, int d)
    {
        if (!root)
        {
            return;
        }

        maxD = max(maxD, d);
        mp[root->val] = d;
        depth(root->left, d + 1);
        depth(root->right, d + 1);
    }
    // T.C : O(n)
    // S.C : O(maxD) system recursion stack space
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        depth(root, 0);

        return LCA(root);
    }
};