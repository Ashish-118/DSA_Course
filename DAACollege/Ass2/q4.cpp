#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(NULL), right(NULL) {}
};

struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

void generateHuffmanCodes(Node *root, string code, unordered_map<char, string> &huffmanCode)
{
    if (!root)
        return;
    if (root->ch != '#')
    {
        huffmanCode[root->ch] = code;
    }
    generateHuffmanCodes(root->left, code + "0", huffmanCode);
    generateHuffmanCodes(root->right, code + "1", huffmanCode);
}

void huffmanCoding(vector<pair<char, int>> &freqTable)
{
    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (auto &p : freqTable)
    {
        pq.push(new Node(p.first, p.second));
    }

    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *newNode = new Node('#', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    unordered_map<char, string> huffmanCode;
    generateHuffmanCodes(pq.top(), "", huffmanCode);

    for (auto &code : huffmanCode)
    {
        cout << code.first << " : " << code.second << endl;
    }
}

int main()
{
    vector<pair<char, int>> freqTable = {
        {'A', 5}, {'B', 9}, {'C', 12}, {'D', 13}, {'E', 16}, {'F', 45}};
    huffmanCoding(freqTable);
    return 0;
}
