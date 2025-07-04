class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> window;
        int left = 0, right = 0, maxLen = 0;

        while (right < s.length())
        {
            if (!window.count(s[right]))
            {
                window.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
                right++;
            }
            else
            {
                window.erase(s[left]);
                left++;
            }
        }

        return maxLen;
    }
};