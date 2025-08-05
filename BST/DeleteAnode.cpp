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
    TreeNode *solve(TreeNode *root, int k)
    {
        if (root == NULL)
            return NULL;

        if (k < root->val)
        {
            root->left = solve(root->left, k);
        }
        else if (k > root->val)
        {
            root->right = solve(root->right, k);
        }
        else
        {
            // Found the node to delete
            if (root->left && root->right)
            {
                TreeNode *temp = root->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                temp->left = root->left;
                TreeNode *nodeToDelete = root;
                root = root->right;
                delete nodeToDelete;
            }
            else if (root->left)
            {
                TreeNode *nodeToDelete = root;
                root = root->left;
                delete nodeToDelete;
            }
            else if (root->right)
            {
                TreeNode *nodeToDelete = root;
                root = root->right;
                delete nodeToDelete;
            }
            else
            {
                delete root;
                return NULL;
            }
        }

        return root;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        return solve(root, key);
    }
};