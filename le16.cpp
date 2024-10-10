#include <iostream>
using namespace std;

void display(int data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
}
void sort(int data[], int size)
{
    // int i = 0;
    // int min = i;
    // int j = 1;
    // while (i<size)
    // {
    //    if (data[j]<min)
    //    {
    //    min=j;
    //    }
    //    if (j==(size-1))
    //    {
    //    swap(data[min],data[i]);
    //     i++;
    //     j=i+1;
    //    }
    //    else{
    //    j++;
    //    }

    // }

    for (int i = 0; i < size-1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (data[j] < data[minIndex])
                minIndex = j;
        }
        swap(data[minIndex], data[i]);
    }
    display(data, size);
}

int main()
{
    int arr[] = {4, 65, 2, 6, 7};
    int size = 5;
    sort(arr, size);

    return 0;
}