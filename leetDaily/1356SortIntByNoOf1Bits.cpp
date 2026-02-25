class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {

        auto comp = [&](int a, int b)
        {
            int b1 = __builtin_popcount(a);
            int b2 = __builtin_popcount(b);

            if (b1 == b2)
                return a < b;
            return b1 < b2;
        };

        sort(begin(arr), end(arr), comp);

        return arr;
    }
};