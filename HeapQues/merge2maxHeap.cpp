#include <bits/stdc++.h>

void heapify(vector<int> &heap, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
    {
        largest = left;
    }

    if (right < n && heap[right] > heap[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}
vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2)
{

    vector<int> mergedHeap = arr1;
    mergedHeap.insert(mergedHeap.end(), arr2.begin(), arr2.end());

    int size = mergedHeap.size();
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(mergedHeap, size, i);
    }

    return mergedHeap;
}