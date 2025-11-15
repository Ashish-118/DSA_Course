#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Pair
    {
        int id;
        int st; // start time
        int ct; // child time consumed
    };

    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        vector<int> timeF(n, 0);
        stack<Pair> st;

        for (const string &log : logs)
        {
            // split by ':'
            string part;
            vector<string> parts;
            stringstream ss(log);
            while (getline(ss, part, ':'))
                parts.push_back(part);

            // parts: [0]=id, [1]="start"/"end", [2]=timestamp
            int id = stoi(parts[0]);
            string typ = parts[1];
            int timestamp = stoi(parts[2]);

            if (typ == "start")
            {
                Pair p;
                p.id = id;
                p.st = timestamp;
                p.ct = 0;
                st.push(p);
            }
            else
            { // "end"
                // pop the corresponding start
                Pair p = st.top();
                st.pop();

                int interval =
                    timestamp - p.st + 1; // total interval (inclusive)
                int time =
                    interval - p.ct; // exclusive time for this function call
                timeF[p.id] += time; // accumulate

                // if a caller exists, add this whole interval to caller's
                // child-time counter
                if (!st.empty())
                {
                    st.top().ct += interval;
                }
            }
        }

        return timeF;
    }
};
