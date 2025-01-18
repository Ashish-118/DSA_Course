class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *LinkedList = nullptr;
        TreeNode *curr = root;

        while (curr != nullptr)
        {

            if (curr->left == nullptr)
            {

                curr = curr->right;
            }
            else
            {

                TreeNode *prev = curr->left;
                while (prev->right != nullptr &&
                       prev->right != curr)
                {
                    prev = prev->right;
                }

                if (prev->right == nullptr)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {

                    prev->right = curr->right;
                    curr->right = curr->left;
                    curr->left = nullptr;
                    LinkedList = curr;

                    curr = prev->right;
                }
            }
        }
        TreeNode *temp = LinkedList;
        while (temp != nullptr && temp->right != nullptr && temp->left != nullptr)
        {
            cout << temp->val;
            temp = temp->right;
        }
    }
};