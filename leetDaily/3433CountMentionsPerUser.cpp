class Solution
{
public:
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>> &events)
    {

        vector<int> ans(numberOfUsers, 0);
        vector<int> userTime(numberOfUsers, 0);
        unordered_map<string, int> mp;
        mp["OFFLINE"] = 2;
        mp["MESSAGE"] = 1;

        sort(begin(events), end(events), [&](vector<string> &a, vector<string> &b)
             {
                 if (a[1] == b[1])
                 {
                     return mp[a[0]] > mp[b[0]];
                 }

                 return stoi(a[1]) < stoi(b[1]); });

        for (auto event : events)
        {
            int timeStamp = stoi(event[1]);
            if (event[0] == "MESSAGE")
            {
                if (event[2] == "ALL")
                {
                    for (int i = 0; i < numberOfUsers; i++)
                    {
                        ans[i]++;
                    }
                }
                else if (event[2] == "HERE")
                {
                    for (int i = 0; i < numberOfUsers; i++)
                    {
                        if (userTime[i] <= timeStamp)
                        {

                            ans[i]++;
                        }
                    }
                }
                else
                {
                    string id = "";
                    for (int x = 0; x < event[2].length(); x++)
                    {
                        if (isdigit(event[2][x]))
                        {
                            id += event[2][x];
                        }
                        else
                        {
                            if (id != "")
                            {

                                ans[stoi(id)]++;
                            }
                            id = "";
                        }
                    }
                    if (id != "")
                    {

                        ans[stoi(id)]++;
                    }
                }
            }
            else
            {
                userTime[stoi(event[2])] = timeStamp + 60;
            }
        }

        return ans;
    }
};