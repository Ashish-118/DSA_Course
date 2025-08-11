struct TrieNode
{
public:
    TrieNode *left;
    TrieNode *right;

    TrieNode()
    {
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void insert(TrieNode *root, int val)
    {
        TrieNode *traverse = root;
        for (int i = 31; i >= 0; i--)
        {
            int ithBit = (val >> i) & 1;
            if (ithBit == 0)
            {
                if (traverse->left == NULL)
                {
                    traverse->left = new TrieNode();
                    traverse = traverse->left;
                }
                else
                {
                    traverse = traverse->left;
                }
            }
            else
            {
                if (traverse->right == NULL)
                {
                    traverse->right = new TrieNode();
                    traverse = traverse->right;
                }
                else
                {
                    traverse = traverse->right;
                }
            }
        }
    }

    int findMaxXor(TrieNode *root, int val)
    {
        TrieNode *traverse = root;
        int maxXor = 0;

        for (int i = 31; i >= 0; i--)
        {
            int ithBit = (val >> i) & 1;

            if (ithBit == 0)
            {
                if (traverse->right != NULL)
                {
                    traverse = traverse->right;
                    maxXor += pow(2, i);
                }
                else
                {
                    traverse = traverse->left;
                }
            }
            else
            {
                if (traverse->left != NULL)
                {
                    traverse = traverse->left;
                    maxXor += pow(2, i);
                }
                else
                {
                    traverse = traverse->right;
                }
            }
        }

        return maxXor;
    }

    int findMaximumXOR(vector<int> &nums)
    {
        TrieNode *root = new TrieNode();

        for (auto &x : nums)
        {
            insert(root, x);
        }

        int maxi = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int temp = findMaxXor(root, nums[i]);
            maxi = max(maxi, temp);
        }
        return maxi;
    }
};