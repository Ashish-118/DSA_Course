class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        set<int> distinct;
        for (auto x : arr)
            distinct.insert(x);

        unordered_map<int, int> mp;
        int prev = 0;
        for (auto d : distinct)
        {
            mp[d] = 1 + prev;

            prev = mp[d];
        }

        vector<int> ans;

        for (int i = 0; i < arr.size(); i++)
        {
            ans.push_back(mp[arr[i]]);
        }

        return ans;
    }
};