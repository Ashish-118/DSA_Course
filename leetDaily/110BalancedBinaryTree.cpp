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
    int balanced(TreeNode *root, bool &check)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = balanced(root->left, check);
        int right = balanced(root->right, check);
        int diff = abs(left - right);

        if (check)
        {
            check = (diff <= 1) ? true : false;
        }

        return max(left, right) + 1;
    }

public:
    bool isBalanced(TreeNode *root)
    {

        if (root == NULL)
            return true;
        bool check = true;
        balanced(root, check);
        return check;
    }
};