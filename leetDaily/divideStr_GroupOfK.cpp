class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        int len = s.length();
        int extra = len % k == 0 ? 0 : k - (len % k);
        int Cextra = extra;
        while (Cextra--)
            s += fill;
        cout << s << endl;
        vector<string> ans;

        for (int i = 0; i < len + extra; i += k)
        {
            ans.push_back(s.substr(i, k));
        }

        return ans;
    }
};