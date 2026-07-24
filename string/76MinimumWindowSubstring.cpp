class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length(), m = t.length();

        unordered_map<char, int> freq, mp;

        for (auto c : t)
            freq[c]++;

        int counter = 0;

        int mini = INT_MAX;
        pair<int, int> minSubArrRange = {-1, -1};

        int left = 0;

        for (int right = 0; right < n; right++)
        {
            if (freq[s[right]] > 0)
            {
                if (mp[s[right]] < freq[s[right]])
                {
                    counter++;
                }
                mp[s[right]]++;
            }

            if (counter == m)
            {
                while (left < n && counter >= m)
                {
                    if (freq[s[left]] > 0)
                    {
                        mp[s[left]]--;

                        if (mp[s[left]] < freq[s[left]])
                        {
                            counter--;
                        }
                    }

                    left++;
                }

                if (mini > (right - left + 2))
                {
                    mini = right - left + 2;
                    minSubArrRange = {left - 1, right};
                }
            }
        }

        if (minSubArrRange.first == -1 || minSubArrRange.second == -1)
            return "";

        return s.substr(minSubArrRange.first, minSubArrRange.second - minSubArrRange.first + 1);
    }
};
