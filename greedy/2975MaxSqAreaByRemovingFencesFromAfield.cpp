#define mod 1000000007
class Solution
{
public:
    int maximizeSquareArea(int m, int n, vector<int> &hFences,
                           vector<int> &vFences)
    {
        unordered_set<int> maxHorizontalLength;
        unordered_set<int> maxVerticalLength;

        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(begin(hFences), end(hFences));
        sort(begin(vFences), end(vFences));

        int l1 = hFences.size(), l2 = vFences.size();

        for (int i = 0; i < l1 - 1; i++)
        {
            for (int j = i + 1; j < l1; j++)
            {
                maxVerticalLength.insert(hFences[j] - hFences[i]);
            }
        }

        for (int i = 0; i < l2 - 1; i++)
        {
            for (int j = i + 1; j < l2; j++)
            {
                maxHorizontalLength.insert(vFences[j] - vFences[i]);
            }
        }

        int maxSq = 0;

        for (auto h : maxHorizontalLength)
        {
            if (maxVerticalLength.find(h) != maxVerticalLength.end())
            {
                maxSq = max(maxSq, h);
            }
        }

        if (maxSq == 0)
        {
            maxSq = -1;
        }
        else
        {
            maxSq = 1ll * maxSq * maxSq % 1000000007;
        }

        return maxSq;
    }
};
