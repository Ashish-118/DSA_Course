class Node
{
public:
    int key;
    int value;
    Node *next;
    Node *prev;
    Node(int k, int v)
    {
        key = k;
        value = v;
        next = prev = NULL;
    }
};

class LRUCache
{
public:
    int size;
    int currSize = 0;
    unordered_map<int, Node *> m;
    Node *head;
    Node *tail;

    LRUCache(int capacity)
    {
        size = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void moveToFront(Node *node)
    {
        // unlink
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // insert after head
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    int get(int key)
    {
        if (m.count(key))
        {
            Node *node = m[key];
            moveToFront(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (m.count(key))
        {
            Node *node = m[key];
            node->value = value;
            moveToFront(node);
        }
        else
        {
            if (currSize == size)
            {
                // evict LRU (node before tail)
                Node *temp = tail->prev;
                m.erase(temp->key); // ✅ erase from map
                temp->prev->next = tail;
                tail->prev = temp->prev;
                delete temp;
                currSize--;
            }
            Node *newNode = new Node(key, value);
            m[key] = newNode;
            // insert after head
            newNode->next = head->next;
            newNode->prev = head;
            head->next->prev = newNode;
            head->next = newNode;
            currSize++;
        }
    }
};
