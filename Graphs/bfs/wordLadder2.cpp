// test cases: 33/38
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});

        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);

        int level = 0;
        vector<vector<string>> ans;

        while (!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();

            // erase all words that have been used in the previous levels to transform
            if (vec.size() > level)
            {
                level++;
                for (auto it : usedOnLevel)
                {
                    st.erase(it);
                }
                usedOnLevel.clear();
            }

            string word = vec.back();

            // store the answers
            if (word == endWord)
            {
                // the first sequence where we reached end
                if (ans.size() == 0)
                {
                    ans.push_back(vec);
                }
                else if (ans[0].size() == vec.size())
                {
                    ans.push_back(vec);
                }
            }

            // wordlength * 26 transformations
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (st.count(word) > 0)
                    {
                        vec.push_back(word);
                        q.push(vec);

                        // mark as visited on the level
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};

// best method

class Solution
{
    string b;
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;

public:
    void dfs(string word, vector<string> &seq)
    {
        if (word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mpp[word];
        int sz = word.size();
        for (int i = 0; i < sz; i++)
        {
            char org = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps)
                {

                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = org;
        }
    }

    vector<vector<string>> findLadders(string st, string tar, vector<string> &word)
    {
        unordered_set<string> s(word.begin(), word.end());
        queue<string> q;
        q.push(st);
        mpp[st] = 1;
        b = st;

        while (!q.empty())
        {
            string str = q.front();
            int steps = mpp[str];
            q.pop();
            if (str == tar)
                break;

            int wordLen = str.size();
            for (int i = 0; i < wordLen; i++)
            {
                char org = str[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    str[i] = ch;
                    if (s.count(str) && mpp.find(str) == mpp.end())
                    {
                        q.push(str);
                        mpp[str] = steps + 1;
                    }
                }
                str[i] = org;
            }
        }
        if (mpp.find(tar) != mpp.end())
        {
            vector<string> seq;
            seq.push_back(tar);
            dfs(tar, seq);
        }

        return ans;
    }
};
