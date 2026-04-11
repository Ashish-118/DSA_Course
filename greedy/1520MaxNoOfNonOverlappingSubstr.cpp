

class Solution
{
public:
    vector<string> maxNumOfSubstrings(string s)
    {
        unordered_map<char, pair<int, int>> letter_range;

        // Step 1: store first and last occurrence
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (letter_range.find(c) == letter_range.end())
            {
                letter_range[c] = {i, i};
            }
            else
            {
                letter_range[c].second = i;
            }
        }

        // Step 2: expand ranges
        for (auto &it : letter_range)
        {
            int start = it.second.first;
            int end = it.second.second;

            stack<pair<int, int>> st;
            st.push({start, end});

            while (!st.empty())
            {
                auto [cur_s, cur_e] = st.top();
                st.pop();

                for (int i = cur_s; i <= cur_e; i++)
                {
                    auto [new_s, new_e] = letter_range[s[i]];

                    if (new_s < start)
                    {
                        st.push({new_s, start - 1});
                        start = new_s;
                    }

                    if (new_e > end)
                    {
                        st.push({end + 1, new_e});
                        end = new_e;
                    }
                }
            }

            it.second = {start, end};
        }

        // Step 3: sort by length
        vector<pair<int, int>> ranges;
        for (auto &it : letter_range)
        {
            ranges.push_back(it.second);
        }

        sort(ranges.begin(), ranges.end(), [](auto &a, auto &b)
             { return (a.second - a.first) < (b.second - b.first); });

        // Step 4: pick non-overlapping substrings
        vector<pair<int, int>> seen_ranges;
        vector<string> ans;

        for (auto &[start, end] : ranges)
        {
            bool overlap = false;

            for (auto &[s1, e1] : seen_ranges)
            {
                if (!(end < s1 || e1 < start))
                { // overlap condition
                    overlap = true;
                    break;
                }
            }

            if (overlap)
                continue;

            seen_ranges.push_back({start, end});
            ans.push_back(s.substr(start, end - start + 1));
        }

        return ans;
    }
};