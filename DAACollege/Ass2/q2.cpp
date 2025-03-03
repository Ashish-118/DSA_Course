#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size(), cols = matrix[0].size();
    int i = 0, j = cols - 1;
    while (i < rows && j >= 0)
    {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)
            j--;
        else
            i++;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{10, 20, 30, 40},
                                  {15, 25, 35, 45},
                                  {27, 29, 37, 48},
                                  {32, 33, 39, 50}};
    int target;
    cin >> target;
    if (searchMatrix(matrix, target))
        cout << "Element found";
    else
        cout << "Element not found";
    return 0;
}
