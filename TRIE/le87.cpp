#include <iostream>
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
        root = new TrieNode('\0');
    }
    void insert(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'A';
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

    bool search(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        TrieNode *child;
        int index = word[0] - 'A';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return search(child, word.substr(1));
    }
    bool searchWord(string word)
    {
        return search(root, word);
    }
    bool hasOtherChildren(TrieNode *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                return true;
            }
        }
        return false;
    }

    void toRemove(TrieNode *&root, string word)
    {
        if (root == NULL)
        {
            cout << "word not found" << endl;
            return;
        }

        if (word.length() == 0)
        {
            if (root->isTerminal)
            {
                root->isTerminal = false;
            }
            else
            {
                cout << "word not found" << endl;
            }
            return;
        }

        int index = word[0] - 'A';
        TrieNode *child = root->children[index];

        if (child == NULL)
        {
            cout << "word not found" << endl;
            return;
        }

        toRemove(child, word.substr(1));

        if (!child->isTerminal && !hasOtherChildren(child))
        {
            delete child;
            root->children[index] = NULL;
        }
    }

    void remove(string word)
    {
        toRemove(root, word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("CAT");
    t->insertWord("CAP");
    t->insertWord("CAPROT");
    t->insertWord("CAPROSE");

    t->remove("CAPROT");
    cout << endl
         << t->searchWord("CAPROSE");
    return 0;
}