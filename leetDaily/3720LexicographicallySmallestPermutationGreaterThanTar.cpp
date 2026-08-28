class Solution
{
public:
    string lexGreaterPermutation(string s, string target)
    {
        vector<int> freq(26, 0);

        for (auto x : s)
            freq[x - 'a']++;
        int n = s.length();

        set<string> st;

        string prefix = "";

        for (int i = 0; i < n; i++)
        {
            char c = target[i];

            char justGreaterChar = ' ';

            for (char ch = c + 1; ch <= 'z'; ch++)
            {
                if (freq[ch - 'a'])
                {
                    justGreaterChar = ch;
                    break;
                }
            }

            if (justGreaterChar != ' ')
            {
                freq[justGreaterChar - 'a']--;
                string temp = prefix + string(1, justGreaterChar);

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    temp += string(freq[ch - 'a'], ch);
                }

                st.insert(temp);

                freq[justGreaterChar - 'a']++;
            }

            if (freq[c - 'a'])
            {
                freq[c - 'a']--;
                prefix += c;
            }
            else
            {
                break;
            }
        }

        return st.empty() ? "" : *st.begin();
    }
};