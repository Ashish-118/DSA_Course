#include <bits/stdc++.h>
using namespace std;

// Standard Trie for Strings
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    int count; // How many words pass through this node
    
    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isEndOfWord = false;
        count = 0;
    }
};

struct Trie {
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& key) {
        TrieNode* curr = root;
        for (char c : key) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
            curr->count++;
        }
        curr->isEndOfWord = true;
    }
    
    bool search(const string& key) {
        TrieNode* curr = root;
        for (char c : key) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) return false;
            curr = curr->children[index];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(const string& prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) return false;
            curr = curr->children[index];
        }
        return true;
    }
};

// Bit Trie for Maximum XOR query
struct BitTrieNode {
    BitTrieNode* children[2];
    BitTrieNode() {
        children[0] = children[1] = nullptr;
    }
};

struct BitTrie {
    BitTrieNode* root;
    BitTrie() { root = new BitTrieNode(); }
    
    void insert(int num) {
        BitTrieNode* curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!curr->children[bit]) {
                curr->children[bit] = new BitTrieNode();
            }
            curr = curr->children[bit];
        }
    }
    
    int getMaxXor(int num) {
        BitTrieNode* curr = root;
        int max_xor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite_bit = 1 - bit;
            if (curr->children[opposite_bit]) {
                max_xor |= (1 << i);
                curr = curr->children[opposite_bit];
            } else if (curr->children[bit]) {
                curr = curr->children[bit];
            } else {
                break;
            }
        }
        return max_xor;
    }
};

void solve() {
    Trie trie;
    trie.insert("hello");
    cout << trie.search("hello") << "\n";
    cout << trie.startsWith("he") << "\n";
    
    BitTrie bTrie;
    bTrie.insert(3);
    bTrie.insert(10);
    bTrie.insert(5);
    cout << bTrie.getMaxXor(8) << "\n"; // Max XOR of 8 with elements in Trie
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
