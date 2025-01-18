#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;
    Heap()
    {
        size = 0;
    }
    void insert(int value)
    {
        int index = size;

        arr[index] = value;
        size++;

        while (index > 0)
        {
            int parentIndex = index / 2;

            if (arr[parentIndex] < arr[index])
            {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            }
            else
            {
                return;
            }
        }
    }

    void delete()
    {
        if (size == 0)
        {
            cout << "Heap is empty!";
            return;
        }
        int index = 0;
        arr[index] = arr[size - 1];
        size--;

        int lchild = 2 * index + 1;
        int rchild = 2 * index + 2;

        while (!(arr[index] > arr[lchild] && arr[index] > arr[rchild]))
        {
            if (arr[lchild] > arr[index])
            {
                swap(arr[index], arr[lchild]);
                index = lchild;
            }
            else
            {
                swap(arr[index], arr[rchild]);
                index = rchild;
            }

            lchild = 2 * index + 1;
            rchild = 2 * index + 2;
        }
    }

    void printHeap()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    Heap h;
    h.insert(100);
    h.insert(80);
    h.insert(60);
    h.insert(82);
    h.insert(55);
    h.insert(76);
    h.insert(20);
    h.printHeap();
    cout << "\nAfter deleting the root element: ";
    h.delete();
    h.printHeap();
    return 0;
}