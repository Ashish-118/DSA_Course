#include <iostream>
#include <vector>

using namespace std;

class TrieNode
{
public:
    char val;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        val = ch;
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
        root = new TrieNode('\0'); // Root node with null character
    }

    void insert(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a'; // Assuming lowercase letters
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insert(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insert(root, word);
    }

    void solve(TrieNode *root, vector<vector<string>> &ans, string queryStr, string iterStr1, string toCheck, int i)
    {
        iterStr1.push_back(root->val);

        if (root->isTerminal)
        {
            if (i >= ans.size())
            {
                ans.resize(i + 1);
            }
            ans[i].push_back(iterStr1);
        }

        for (int j = 0; j < 26; j++)
        {
            if (root->children[j] != NULL)
            {
                solve(root->children[j], ans, queryStr, iterStr1, toCheck, i);
            }
        }

        if (toCheck == iterStr1 && queryStr.length() > 0)
        {
            queryStr = queryStr.substr(1);
            int index = queryStr[0] - 'a';
            toCheck.push_back(queryStr[0]);
            TrieNode *child = root->children[index];

            if (child == NULL)
                return;

            solve(child, ans, queryStr, iterStr1, toCheck, i + 1);
        }
    }

    vector<vector<string>> start(string queryStr)
    {
        vector<vector<string>> ans;
        string iterStr1 = "";
        string toCheck(1, queryStr[0]);
        int index = queryStr[0] - 'a';
        TrieNode *child = root->children[index];

        if (child != NULL)
        {
            solve(child, ans, queryStr, iterStr1, toCheck, 0);
        }

        return ans;
    }
};

// vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
// {

//     Trie *t = new Trie();
//     for (int i = 0; i < contactList.size(); i++)
//         t->insertWord(contactList[i]);

//     return t->start(queryStr);
// }

int main()
{
    Trie *t = new Trie();
    t->insertWord("cat");
    t->insertWord("code");
    t->insertWord("coding");
    t->insertWord("cod");

    string queryStr = "cod";
    vector<vector<string>> ans = t->start(queryStr);

    for (auto &x : ans)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    delete t; // Free memory
    return 0;
}