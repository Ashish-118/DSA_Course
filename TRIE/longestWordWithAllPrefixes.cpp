#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isTerminal;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *temp = root;
        for (auto &ch : word)
        {
            int index = ch - 'a';
            if (temp->children[index] == NULL)
            {
                temp->children[index] = new TrieNode();
            }
            temp = temp->children[index];
        }
        temp->isTerminal = true;
    }

    bool checkAllPrefixes(string &word)
    {
        TrieNode *temp = root;
        for (auto &ch : word)
        {
            int index = ch - 'a';
            if (temp->children[index] == NULL || temp->children[index]->isTerminal == false)
            {
                return false; // prefix missing
            }
            temp = temp->children[index];
        }
        return true;
    }
};

string longestCompleteString(vector<string> &words)
{
    Trie T;
    for (auto &w : words)
        T.insert(w);

    string ans = "";
    for (auto &w : words)
    {
        if (T.checkAllPrefixes(w))
        {
            if (w.length() > ans.length() || (w.length() == ans.length() && w < ans))
            {
                ans = w;
            }
        }
    }
    return ans.empty() ? "None" : ans;
}

int main()
{
    vector<string> words = {"n", "ni", "nin", "ninj", "nindd", "nil"};
    // vector<string> words = {"ninja", "night", "nil"};
    cout << longestCompleteString(words) << endl;
    return 0;
}
