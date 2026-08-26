class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        set<string> poss;

        int n = s.length();

        int countOnes = 0;
        int miniLength = INT_MAX;

        int left = 0;

        for (int right = 0; right < n; right++)
        {
            if (s[right] == '1')
            {
                countOnes++;
            }

            while (left < n && countOnes == k)
            {
                if (countOnes == k)
                {
                    // miniLength = min(miniLength, right - left + 1);

                    if (miniLength == (right - left + 1))
                    {
                        poss.insert(s.substr(left, right - left + 1));
                    }
                    else if (miniLength > (right - left + 1))
                    {
                        poss.clear();
                        miniLength = right - left + 1;
                        poss.insert(s.substr(left, right - left + 1));
                    }
                }

                if (s[left] == '1')
                {
                    countOnes--;
                }

                left++;
            }
        }

        // for (auto x : poss) {
        //     cout << x << " ";
        // }
        // cout << endl;

        return poss.empty() ? "" : *poss.begin();
    }
};