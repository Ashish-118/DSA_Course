
class Solution
{
    pair<int, bool> solve(TreeNode *root)
    {
        if (root == NULL)
            return {INT_MAX, true};
        else if ((root->left == NULL && root->right == NULL))
        {
            return {root->val, true};
        }

        pair<int, bool> left = solve(root->left);
        pair<int, bool> right = solve(root->right);

        if ((left.first < root->val && root->val <= right.first) && (left.second && right.second))
        {
            return {root->val, true};
        }
        return {INT_MAX, false};
    }

public:
    bool isValidBST(TreeNode *root)
    {
        pair<int, bool> ans = solve(root);
        return ans.second;
    }
};

///////////

// bool solve(BinaryTreeNode<int> *root, int min, int max)
// {
//     if (root == NULL)
//         return true;
//     if (root->data > min && root->data < max)
//     {
//         bool l = solve(root->left, min, root->data);
//         bool r = solve(root->right, root->data, max);
//         return l * r;
//     }
//     else
//     {
//         return false;
//     }
// }
// bool validateBST(BinaryTreeNode<int> *root)
// {
//     return solve(root, INT_MIN, INT_MAX);
// }