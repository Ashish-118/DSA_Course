/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
pair<int, int> solve(TreeNode<int> *root, int &maxi, bool verify)
{
    if (root == NULL)
        return {0, 0};

    pair<int, int> l = solve(root->left, maxi, verify);
    if (maxi > root->data && !verify)
    {
        verify = true;
    }
    pair<int, int> r = solve(root->right, maxi, verify);
    if ((maxi < root->data) && !(r.first == 0 && r.second == 0))
    {
        verify = true;
    }

    maxi = (maxi < root->data) ? root->data : maxi;
    int curr_val = root->data;
    int val = curr_val, count;
    if (verify)
    {
        maxi = 0;
        val = -1;
        count = max(l.second, r.second);
    }
    else if (l.second == 0 && r.second == 0)
    {
        count = 1;
    }
    else if (l.first == -1 || r.first == -1)
    {
        val = -1;
        count = max(l.second, r.second);
    }
    else if ((l.first < curr_val) && (curr_val < r.first || r.first == 0))
    {
        count = l.second + r.second + 1;
    }
    else
    {
        val = -1;
        count = max(l.second, r.second);
    }
    return {val, count};
}
int largestBST(TreeNode<int> *root)
{
    int maxi = 0;
    int v = false;
    pair<int, int> ans = solve(root, maxi, v);
    return ans.second;
}