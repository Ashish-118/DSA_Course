class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        queue<int> q;
        q.push(0);

        int n = s.length();

        int idx = 0;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            if (front == n - 1)
                return true;

            int l = max(front + minJump, idx);

            int r = min(front + maxJump, n - 1);

            for (int i = l; i <= r; i++)
            {
                if (s[i] == '0')
                {
                    q.push(i);
                }
            }
            idx = r + 1;
        }

        return false;
    }
};