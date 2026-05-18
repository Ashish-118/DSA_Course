class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers,
                                 vector<int> &people)
    {
        int n = people.size();
        vector<int> bloom;
        vector<int> dead;
        int f = flowers.size();
        for (auto x : flowers)
        {
            bloom.push_back(x[0]);
            dead.push_back(x[1]);
        }
        sort(begin(bloom), end(bloom));
        sort(begin(dead), end(dead));

        auto flowers_bloom = [&](int x)
        {
            int bloomIdx =
                upper_bound(begin(bloom), end(bloom), x) - begin(bloom);
            int bloomedFlowers = f;

            if (bloomIdx < f)
            {
                bloomedFlowers = bloomIdx;
            }
            int deadIdx = lower_bound(begin(dead), end(dead), x) - begin(dead);
            int deadFlowers = f;

            if (deadIdx < f)
            {
                deadFlowers = (deadIdx);
            }

            cout << bloomedFlowers << endl;
            cout << deadFlowers << endl;

            return bloomedFlowers - deadFlowers;
        };

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {

            ans[i] = flowers_bloom(people[i]);
        }

        return ans;
    }
};