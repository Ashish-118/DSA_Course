class Solution
{
public:
    vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
    {
        vector<pair<string, string>> v;
        int n = code.size();
        unordered_map<string, int> mp;
        mp["electronics"] = 1;
        mp["grocery"] = 2;
        mp["pharmacy"] = 3;
        mp["restaurant"] = 4;

        for (int i = 0; i < n; i++)
        {
            bool check = true;
            if (code[i].empty())
                continue;
            for (auto c : code[i])
            {
                if ((c != '_' && !isalpha(c) && !isdigit(c)))
                {
                    check = false;
                    break;
                }
            }
            if (!check)
                continue;

            if (mp.count(businessLine[i]) == 0)
                continue;

            if (!isActive[i])
                continue;

            v.push_back({code[i], businessLine[i]});
        }

        sort(begin(v), end(v), [&](pair<string, string> &a, pair<string, string> &b)
             {
          if(a.second==b.second) return a.first<b.first;
          return mp[a.second]<mp[b.second]; });

        vector<string> ans;
        for (auto x : v)
        {
            ans.push_back(x.first);
        }
        return ans;
    }
};