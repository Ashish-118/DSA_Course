// LeetCode problem number: 3085

// LeetCode problem name: Minimum Deletions to Make String K-Special
// some logic issue but 633 / 732 testcases passed

#include <vector>
class Solution
{
public:
    int minimumDeletions(string word, int k)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < word.length(); i++)
        {
            freq[word[i] - 'a']++;
        }
        sort(freq.begin(), freq.end());

        int ans = 0;
        int s = 0, e = freq.size() - 1;
        while (freq[s] != 0)
        {
            s++;
            break;
        }
        while (abs(freq[s] - freq[e]) > k && s <= e)
        {
            if (freq[s] < abs(freq[e] - freq[s] - k))
            {
                ans += freq[s];
                freq[s] = 0;
            }
            else
            {
                ans += abs(freq[e] - freq[s] - k);
                freq[e] -= abs(freq[e] - freq[s] - k);
            }
            s++;
        }
        return ans;
    }
};

// correct solutions

class Solution
{
public:
    int minimumDeletions(string word, int k)
    {
        unordered_map<char, int> cnt;
        for (auto &ch : word)
        {
            cnt[ch]++;
        }
        int res = word.size();
        for (auto &[_, a] : cnt)
        {
            int deleted = 0;
            for (auto &[_, b] : cnt)
            {
                if (a > b)
                {
                    deleted += b;
                }
                else if (b > a + k)
                {
                    deleted += b - (a + k);
                }
            }
            res = min(res, deleted);
        }
        return res;
    }
};
