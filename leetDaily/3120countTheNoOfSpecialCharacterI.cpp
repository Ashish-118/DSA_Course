class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        int ans = 0;
        unordered_set<char> st;
        for (auto x : word)
        {
            if ('A' <= x && x <= 'Z')
                st.insert(x);
        }

        for (auto x : st)
        {
            int idx1 = x - 'A';

            for (auto y : word)
            {
                if ('a' <= y && y <= 'z')
                {
                    int idx2 = y - 'a';
                    if (idx1 == idx2)
                    {
                        ans++;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};