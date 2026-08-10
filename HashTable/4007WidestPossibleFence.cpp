class Solution
{
public:
    int maximumWidth(vector<int> &planks)
    {
        int n = planks.size();

        unordered_map<int, int> freq;
        unordered_map<long long, int> width;

        int ans = 0;

        for (int x : planks)
        {
            freq[x]++;
            width[x]++;
            ans = max(ans, freq[x]);
        }

        for (auto &it1 : freq)
        {
            for (auto &it2 : freq)
            {

                long long sum = 1LL * it1.first + it2.first;

                if (it1.first < it2.first)
                {
                    width[sum] += min(it1.second, it2.second);
                }
                else if (it1.first == it2.first)
                {
                    width[sum] += it1.second / 2;
                }
            }
        }

        for (auto it : width)
        {
            ans = max(ans, it.second);
        }

        return ans;
    }
};