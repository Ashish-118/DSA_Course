#define mod 1000000007
class Solution
{
public:
    int sum(int a, int b)
    {
        return (a % mod + b % mod) % mod;
    }

    void solve(map<char, int> &mp, map<char, int>::iterator it, int k, int len, int &count)
    {
        if (it == mp.end() && len >= k)
        {
            count = sum(count, 1);
            return;
        }

        for (int x = it->second; x > 0; x--)
        {
            solve(mp, next(it), k, len + x, count);
        }
    }
    int possibleStringCount(string word, int k)
    {
        map<char, int> freq;
        for (auto x : word)
            freq[x]++;
        int size = freq.size();
        int count = 0;
        solve(freq, freq.begin(), k, 0, count);
        return count;
    }
}; // we need to change the data structure
