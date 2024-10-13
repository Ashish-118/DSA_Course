// TreeNode *searchBST(TreeNode *root, int val)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }
//     if (root->val == val)
//     {
//         return root;
//     }

//     TreeNode *find;
//     if (root->val < val)
//     {
//         find = searchBST(root->right, val);
//     }
//     else
//     {
//         find = searchBST(root->left, val);
//     }

//     return find;
// }

// Iterative mehtod
TreeNode *searchBST(TreeNode *root, int val)
{
    TreeNode *temp = root;

    while (temp != NULL)
    {
        if (temp->val == val)
        {
            return temp;
        }

        if (temp->val < val)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return NULL;
}