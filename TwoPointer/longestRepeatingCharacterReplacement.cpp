class Solution
{
public:
    int characterReplacement(string s, int k)
    {

        int ans = 0;
        int n = s.length();

        for (char c = 'A'; c <= 'Z'; c++)
        {
            int count = 0;
            int left = 0;

            for (int right = 0; right < n; right++)
            {
                if (s[right] != c)
                    count++;

                while (count > k)
                {
                    if (s[left] != c)
                        count--;

                    left++;
                }

                ans = max(ans, right - left + 1);
            }
        }

        return ans;
    }
};