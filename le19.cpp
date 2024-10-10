#include <iostream>
using namespace std;

void display(int data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
}
void insertionsort(int data[], int size)
{
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         if (data[i] < data[j])
    //         {
    //             swap(data[i], data[j]);
    //         }
    //     }
    // }

//  method 2 by code help babbar 
    for (int i = 1; i < size; i++)
    {
        int temp = data[i];
        int j = i- 1;
        for (; j >= 0; j--)
        {
            if (data[j] > temp)
            {
                // shift
                data[j + 1] = data[j];
            }
            else
            { // ruk jao break;
            break;
            }
        }
        data[j + 1] = temp;
    }

    display(data, size);
}

int main()
{

    int arr[] = {4, 65, 2, 6, 7};
    int size = 5;
    // int arr[] = {4, 65, 2, 6, 7, -1, 0, -3, 44};
    // int size = 8;
    insertionsort(arr, size);

    return 0;
}
