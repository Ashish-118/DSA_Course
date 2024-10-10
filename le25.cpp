#include <iostream>
using namespace std;

bool isPresent(int arr[][4], int target, int row, int col)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (arr[row][col] == target)
            {
                return 1;
            }
        }
    }

    return 0;
}

void printColSumint(int arr[][3], int row, int col)
{
    cout << "Printing Sum ->" << endl;
    for (int col = 0; col < 3; col++)
    {
        int sum = 0;
        for (int row = 0; row < 3; row++)
        {
            sum+=arr[row][col];
        }
        cout << sum << " ";
    }

    cout << endl;
}

void spiral(int arr[][],int col, int row){
    int row_top=0;
    int row_bottom=row;
    int column_start=0;
    int column_end=col;
int temp[]={0};
    for (int i = column_start; i <= column_end; i++)
    {
       temp[i]=arr[row_top][i];
    }
    
}
int main()
{
    // create 2 d array
    // int arr[3][4];
    int arr[3][3];
    // int arr [3] [41 = {1, 27, 3, 4,5,6, 7,8,9,10,14, 16};
    // int arr 31 [4] = {{1, 11, 111, 1111}, {2, 22, 222, 2222}, {3, 33, 333, 3333}};

    // taking input -> row wise input
    // for (int row = 0; row < 3; row++)
    // {
    //     for (int col = 0; col < 4; col++)
    //     {
    //         cin >> arr[row][col];
    //     }
    // }

    // taking input →> col wise input
    for (int col = 0; col < 3; col++)
    {
        for (int row = 0; row < 3; row++)
        {
            cin >> arr[row][col];
        }
    }

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << arr[row][col] << "";
        }
        cout << endl;
    }

    // cout << " Enter the element to search " << endl;
    // int target;
    // cin >> target;
    // if (isPresent(arr, target, 3, 4))
    // {
    //     cout << "Element found " << endl;
    // }
    // else
    // {
    //     cout << " Not Found" << endl;
    // }

    // printColSumint(arr,3,3);

    return 0;
}