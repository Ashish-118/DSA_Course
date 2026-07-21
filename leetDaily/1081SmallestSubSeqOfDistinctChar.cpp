class Solution
{
public:
    string smallestSubsequence(string s)
    {
        unordered_set<int> distinct;
        for (auto x : s)
            distinct.insert(x - 'a');

        int len = distinct.size();
        int n = s.length();

        string ans = "";

        unordered_set<int> elements;

        vector<bool> visited(26, false);

        int idx = -1;

        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < 26; j++)
            {

                if (visited[j] || distinct.find(j) == distinct.end())
                    continue;

                unordered_set<int> avail;

                bool found = false;
                int foundIdx = -1;

                for (int x = idx + 1; x < n; x++)
                {

                    if (!found && s[x] == (j + 'a'))
                    {
                        found = true;
                        foundIdx = x;
                    }

                    if (found && elements.find(s[x] - 'a') == elements.end())
                    {
                        avail.insert(s[x] - 'a');
                    }
                }

                if ((len - ans.length()) == avail.size())
                {
                    ans = ans + string(1, j + 'a');
                    elements.insert(j);
                    idx = foundIdx;

                    visited[j] = true;

                    break;
                }
            }
        }

        return ans;
    }
};

// optimal approach using monotonic stack

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26, -1);
        vector<bool> seen(26, false);
        string result;
        
        // Step 1: Record the last occurrence of each character
        for (int i = 0; i < s.length(); ++i) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        // Step 2: Build the monotonic stack
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            int idx = c - 'a';
            
            // Skip if character is already in result
            if (seen[idx]) continue;
            
            // Pop larger characters that appear again later
            while (!result.empty() && 
                   result.back() > c && 
                   lastIndex[result.back() - 'a'] > i) {
                
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            // Add current character
            result.push_back(c);
            seen[idx] = true;
        }
        
        return result;
    }
};