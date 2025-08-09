class TrieNode
{
public:
    char val;
    bool isTerminal;
    TrieNode *children[26];

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

    void insert(string word)
    {
        TrieNode *temp = root;
        for (auto x : word)
        {
            int index = x - 'a';
            if (temp->children[index] == NULL)
            {
                temp->children[index] = new TrieNode(x);
            }
            temp = temp->children[index];
        }
        temp->isTerminal = true;
    }

    bool search(string word)
    {
        TrieNode *temp = root;
        for (auto x : word)
        {
            int index = int(x) - 'a';

            if (temp->children[index] == NULL)
            {
                return false;
            }
            else
            {
                temp = temp->children[index];
            }
        }

        return temp->isTerminal;
    }

    bool startsWith(string prefix)
    {
        TrieNode *temp = root;
        for (auto x : prefix)
        {
            int index = int(x) - 'a';

            if (temp->children[index] == NULL)
            {
                return false;
            }
            else
            {
                temp = temp->children[index];
            }
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */