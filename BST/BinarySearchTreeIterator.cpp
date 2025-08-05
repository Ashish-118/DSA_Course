class BSTIterator
{
    stack<TreeNode *> st;

    void pushLeft(TreeNode *node)
    {
        while (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        pushLeft(root);
    }

    int next()
    {
        TreeNode *curr = st.top();
        st.pop();
        if (curr->right != NULL)
        {
            pushLeft(curr->right);
        }
        return curr->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};
