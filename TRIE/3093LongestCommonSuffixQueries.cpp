class Trie
{
public:
    Trie *children[26];
    int idx;

    Trie(int i)
    {

        for (int j = 0; j < 26; j++)
        {
            children[j] = NULL;
        }

        idx = i;
    }
    ~Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            delete children[i];
        }
    }
};

class Solution
{
public:
    Trie *root;

    void buildTrie(string word, int i, vector<string> &wordsContainer)
    {

        Trie *temp = root;

        for (int idx = word.length() - 1; idx >= 0; idx--)
        {

            char c = word[idx];

            if (temp->children[c - 'a'] == NULL)
            {

                temp->children[c - 'a'] = new Trie(i);
            }
            else
            {

                int prevIdx = temp->children[c - 'a']->idx;

                if (wordsContainer[prevIdx].size() > wordsContainer[i].size())
                {

                    temp->children[c - 'a']->idx = i;
                }
            }

            temp = temp->children[c - 'a'];
        }
    }

    int solveQuery(string word)
    {

        Trie *temp = root;

        int ans = root->idx;

        for (int idx = word.length() - 1; idx >= 0; idx--)
        {

            char c = word[idx];

            if (temp->children[c - 'a'] == NULL)
            {
                break;
            }

            temp = temp->children[c - 'a'];

            ans = temp->idx;
        }

        return ans;
    }

    vector<int> stringIndices(vector<string> &wordsContainer,
                              vector<string> &wordsQuery)
    {

        root = new Trie(0);

        // store globally smallest string index at root
        for (int i = 0; i < wordsContainer.size(); i++)
        {

            if (wordsContainer[root->idx].size() > wordsContainer[i].size())
            {

                root->idx = i;
            }

            buildTrie(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;

        for (auto query : wordsQuery)
        {

            ans.push_back(solveQuery(query));
        }

        delete root;

        return ans;
    }
};
