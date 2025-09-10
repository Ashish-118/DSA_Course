class Trie
{
public:
    Trie *left;
    Trie *right;
    int val; // ✅ store number at leaf

    Trie()
    {
        left = NULL;
        right = NULL;
        val = -1;
    }
};

class Solution
{
public:
    Trie *root;

    // Insert a number into the Trie
    void insert(int val)
    {
        Trie *traverse = root;
        for (int bit = 31; bit >= 0; bit--)
        {
            int ithBit = (val >> bit) & 1;
            if (ithBit)
            {
                if (!traverse->right)
                    traverse->right = new Trie();
                traverse = traverse->right;
            }
            else
            {
                if (!traverse->left)
                    traverse->left = new Trie();
                traverse = traverse->left;
            }
        }
        traverse->val = val; // ✅ mark leaf with actual number
    }

    // Find the best partner for "val"
    int findBest(int val, Trie *node, int bit)
    {
        if (!node)
            return -1;
        if (bit < 0)
            return node->val; // ✅ reached leaf

        int ithBit = (val >> bit) & 1;

        if (ithBit == 1)
        {
            // must go left (bit=0) to avoid common 1
            return findBest(val, node->left, bit - 1);
        }
        else
        {
            // prefer right (bit=1) for bigger partner
            int res1 = findBest(val, node->right, bit - 1);
            if (res1 != -1)
                return res1;
            return findBest(val, node->left, bit - 1);
        }
    }

    long long maxProduct(vector<int> &nums)
    {
        root = new Trie();
        for (int x : nums)
            insert(x);

        long long ans = 0;
        for (int x : nums)
        {
            int y = findBest(x, root, 31);
            if (y != -1 && (x & y) == 0)
            { // ✅ ensure no common set bits
                ans = max(ans, 1LL * x * y);
            }
        }
        return ans;
    }
};
