class Solution
{
public:
    int minOperations(string s)
    {
        int n = s.length();

        int mini = INT_MAX;
        int leftRotation = 0;

        for (int x = 1; x <= n; x++)
        {

            char c = s[0];
            s = s.substr(1) + c;

            if (x != n)
            {
                leftRotation++;
            }
            else
            {
                leftRotation = 0;
            }

            int count = 0;

            for (int i = 0; i < n / 2; i++)
            {
                count += min(abs(s[i] - s[n - 1 - i]),
                             26 - abs(s[i] - s[n - 1 - i]));
            }

            mini = min(mini, count + leftRotation);
        }

        return mini;
    }
};


/// java code----------------

class Solution
{
public
    int minOperations(String s)
    {
        int n = s.length();

        int mini = Integer.MAX_VALUE;
        int leftRotation = 0;

        for (int x = 1; x <= n; x++)
        {
            char c = s.charAt(0);

            s = s.substring(1) + c;

            if (x != n)
            {
                leftRotation++;
            }
            else
            {
                leftRotation = 0;
            }

            int count = 0;

            for (int i = 0; i < n / 2; i++)
            {
                char ith = s.charAt(i);
                char jth = s.charAt(n - 1 - i);
                count += Math.min(Math.abs(ith - jth), 26 - Math.abs(ith - jth));
            }

            mini = Math.min(mini, count + leftRotation);
        }

        return mini;
    }
}