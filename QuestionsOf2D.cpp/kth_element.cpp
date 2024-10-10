#include <iostream>
using namespace std;
// Question is we gotto find the kth smallest element from the 2d Matrix
int kthSmallest(int mat[4][4], int n, int k)
{
    int linearArray[n * n];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            linearArray[index] = mat[i][j];
            index++;
        }
    }

    for (int c = 0; c < k; c++)
    {
        int Min = INT_MAX;
        // int index=0;
        int check = 0;

        for (int i = 0; i < n * n; i++)
        {
            if (linearArray[i] < Min)
            {
                Min = linearArray[i];
                check = i;
            }
        }

        if (c == (k - 1))
        {
            return linearArray[check];
        }
        else
        {
            linearArray[check] = INT_MAX;
        }
    }
}

int main()
{
    int arr[][4] = {{16, 28, 60, 64},
                    {22, 41, 63, 91},
                    {27, 50, 87, 93},
                    {36, 78, 87, 94}};
    cout << kthSmallest(arr, 4, 3);
    return 0;
}