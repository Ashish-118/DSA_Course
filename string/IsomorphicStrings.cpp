class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {

        unordered_map<char, char> m1;
        unordered_map<char, char> m2;
        int n = s.length();
        char s1 = '0';
        char s2 = '0';
        for (int i = 0; i < n; i++)
        {
            if (m1.count(s[i]) == 0)
            {
                m1[s[i]] = s1;
                s1++;
            }
            if (m2.count(t[i]) == 0)
            {
                m2[t[i]] = s2;
                s2++;
            }
        }

        string str1 = "", str2 = "";

        for (int i = 0; i < n; i++)
        {
            str1 += m1[s[i]];
            str2 += m2[t[i]];
        }

        return str1 == str2;
    }
};

// optimal approach O(n) time and O(1) space

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, int> charIndexS;
        unordered_map<char, int> charIndexT;

        for (int i = 0; i < s.length(); i++)
        {
            if (charIndexS.find(s[i]) == charIndexS.end())
            {
                charIndexS[s[i]] = i;
            }

            if (charIndexT.find(t[i]) == charIndexT.end())
            {
                charIndexT[t[i]] = i;
            }

            if (charIndexS[s[i]] != charIndexT[t[i]])
            {
                return false;
            }
        }

        return true;
    }
};