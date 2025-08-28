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

    ~TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            delete children[i];
        }
    }
};

class Trie
{
public:
    TrieNode *root;
    vector<string> ans;

    Trie()
    {
        root = new TrieNode('\0');
    }

    ~Trie()
    {
        delete root;
    }

    void insert(string word)
    {
        TrieNode *temp = root;
        string str = "";
        for (auto x : word)
        {
            int index = x - 'a';
            if (temp->children[index] == NULL)
            {
                str += x;
                ans.push_back(str); // push only when new node is created
                temp->children[index] = new TrieNode(x);
            }
            else
            {
                str += x;
            }
            temp = temp->children[index];
        }
        temp->isTerminal = true;
    }
};

int countDistinctSubstring(string s)
{
    Trie T;
    for (int i = 0; i < s.length(); i++)
    {
        T.insert(s.substr(i));
    } // here destructors of TrieNode will handle memory cleanup
    // and we don't need to explicitly delete nodes
    // as Trie destructor will take care of it.
    // The destructor of Trie will delete the root node,
    // which in turn will delete all its children recursively.
    // Thus, we don't need to worry about memory leaks.

    return T.ans.size() + 1; // +1 for empty substring
}
