class Solution
{
public:
    vector<string> twoEditWords(vector<string> &queries,
                                vector<string> &dictionary)
    {
        vector<string> ans;

        int q = queries.size();
        int d = dictionary.size();
        int len = queries[0].size();

        for (int i = 0; i < q; i++)
        {
            for (int j = 0; j < d; j++)
            {
                int dist = 0;
                for (int idx = 0; idx < len; idx++)
                {
                    if (dictionary[j][idx] != queries[i][idx])
                    {
                        dist++;
                    }
                }

                if (dist <= 2)
                {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }

        return ans;
    }
};