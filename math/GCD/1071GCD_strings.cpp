class Solution
{
public:
    int countSubstring(const string &s, const string &sub)
    {
        int count = 0;
        //   auto pos = 0;  // can use this as well
        size_t pos = 0;

        while ((pos = s.find(sub, pos)) != string::npos)
        {
            count++;
            pos += sub.size(); // move forward (non-overlapping)
        }
        return count;
    }

    string gcdOfStrings(string str1, string str2)
    {
        if (str1.length() > str2.length())
            return gcdOfStrings(str2, str1);

        int n1 = str1.length();

        string check = "";
        string ans = "";

        for (int i = 0; i < n1; i++)
        {
            check += str1[i];

            bool l1 = ((countSubstring(str1, check) * check.length()) ==
                       str1.length());
            bool l2 = ((countSubstring(str2, check) * check.length()) ==
                       str2.length());

            if (l1 && l2)
            {
                ans = check;
            }
        }

        return ans;
    }
};