class Solution
{
public:
    void convertTolower(string &str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            str[i] = tolower(str[i]);
        }
    }
    void replaceVowels(string &str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            char c = str[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                str[i] = '*';
            }
        }
    }
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        unordered_map<string, int> same;
        unordered_map<string, string> lowerRep;
        unordered_map<string, string> vowelRep;
        for (auto str : wordlist)
        {
            same[str] = 1;
            string lowered = str;
            convertTolower(lowered);
            if (lowerRep.count(lowered) == 0)
                lowerRep[lowered] = str;

            string vow = lowered;
            replaceVowels(vow);
            if (vowelRep.count(vow) == 0)
                vowelRep[vow] = str;
        }
        vector<string> ans;
        for (auto qr : queries)
        {
            string lowered = qr;
            convertTolower(lowered);
            string vow = lowered;
            replaceVowels(vow);

            if (same[qr])
            {
                ans.push_back(qr);
            }
            else if (lowerRep.count(lowered) > 0)
            {
                ans.push_back(lowerRep[lowered]);
            }
            else if (vowelRep.count(vow) > 0)
            {
                ans.push_back(vowelRep[vow]);
            }
            else
            {
                ans.push_back("");
            }
        }
        return ans;
    }
};