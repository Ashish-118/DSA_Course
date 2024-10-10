#include <iostream>
using namespace std;

void display(int data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
}
void bubblesort(int data[], int size)
{
    bool swapped=false;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (data[j] >data[j + 1])
            {
                swap(data[j], data[j + 1]);
                swapped=true;
            }
        }
        if (swapped==false)
        {
            break;
        }
        
    }
             
    display(data,size);
}
int main()
{

        int arr[] = {4, 65, 2, 6, 7,-1,0,44};
    int size = 8;
    bubblesort(arr, size);

    return 0;
}
