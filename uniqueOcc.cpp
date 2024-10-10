#include <iostream>
using namespace std;

int main()
{

    int size;
    cout << "Enter the Size of Array : ";
    cin >> size;

    int arr[size];
    for (int index = 0; index < size; index++)
    {
        cout << "Enter the Array  " << index << " elements ";
        cin >> arr[index];
    }

    for (int i = 0; i < size; i++)
    {
        bool verify = true;

        for (int j = 0; j < size; j++)
        {
            if ((arr[i] == arr[j]) && (i!=j))
            {

                verify = false;
                break;
            }
        }
        if (verify)
        {
            cout << arr[i] << endl;
            break; 
        }
    }


}