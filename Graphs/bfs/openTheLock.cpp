class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_map<string, bool> visited;

        for (auto x : deadends)
        {
            if (x == "0000")
                return -1;
            visited[x] = true;
        }
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        visited["0000"] = true;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            string node = front.first;
            int lvl = front.second;

            if (node == target)
            {
                cout << node << endl;
                return lvl;
            }
            for (int i = 0; i < 4; i++)
            {
                string temp1 = node;
                string temp2 = node;
                temp1[i] = (temp1[i] - '0' + 1) % 10 + '0';
                temp2[i] =
                    (temp2[i] - '0' - 1 < 0) ? '9' : (temp2[i] - '0' - 1) + '0';

                if (!visited[temp1])
                {
                    q.push({temp1, lvl + 1});
                    visited[temp1] = true;
                }

                if (!visited[temp2])
                {
                    q.push({temp2, lvl + 1});
                    visited[temp2] = true;
                }
            }
        }

        return -1;
    }
};