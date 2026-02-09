class MyCircularQueue
{
public:
    vector<int> v;
    int idx;
    int size;
    int front = 0;
    int currCapacity = 0;
    MyCircularQueue(int k)
    {
        v = vector<int>(k, -1);
        size = k;
        idx = -1;
    }

    bool enQueue(int value)
    {
        if (currCapacity == size)
        {
            return false;
        }

        currCapacity++;

        idx = (idx + 1) % size;
        v[idx] = value;
        return true;
    }

    bool deQueue()
    {
        if (currCapacity == 0)
            return false;

        v[front] = -1;
        front = (front + 1) % size;
        currCapacity--;
        return true;
    }

    int Front() { return v[front]; }

    int Rear()
    {
        if (idx < 0)
            return -1;
        return v[idx];
    }

    bool isEmpty() { return currCapacity == 0; }

    bool isFull() { return currCapacity == size; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */