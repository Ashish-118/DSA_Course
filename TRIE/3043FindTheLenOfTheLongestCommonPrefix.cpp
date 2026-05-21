class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_set<string> st;

        for (auto a : arr1)
        {
            string s = "";
            string str = to_string(a);
            for (auto c : str)
            {
                s += c;
                st.insert(s);
            }
        }

        int ans = 0;

        for (auto a : arr2)
        {
            string s = "";
            string str = to_string(a);
            for (auto c : str)
            {
                s += c;
                if (st.find(s) != st.end())
                {
                    int len = s.length();
                    ans = max(ans, len);
                }
            }
        }

        return ans;
    }
};

/// optimal solution using trie

class trie
{
public:
    int val;
    trie *children[10];

    trie(int digit)
    {
        val = digit;

        for (int i = 0; i < 10; i++)
        {
            children[i] = NULL;
        }
    }
};

class Solution
{
public:
    trie *root;

    void build(int num)
    {
        string str = to_string(num);
        trie *temp = root;

        for (auto x : str)
        {

            int digit = x - '0';
            if (temp->children[digit] != NULL)
            {
                temp = temp->children[digit];
            }
            else
            {
                temp->children[digit] = new trie(digit);
                temp = temp->children[digit];
            }
        }
    }
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        root = new trie(-1);

        for (auto num : arr1)
        {
            build(num);
        }

        int ans = 0;

        for (auto num : arr2)
        {
            string str = to_string(num);
            trie *temp = root;
            int len = 0;

            for (auto x : str)
            {

                int digit = x - '0';
                if (temp->children[digit] != NULL)
                {
                    temp = temp->children[digit];
                    len++;
                }
                else
                {
                    break;
                }
            }
            ans = max(ans, len);
        }

        return ans;
    }
};