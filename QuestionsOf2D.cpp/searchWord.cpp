#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int countWord(vector<vector<char > > matrix, string target)
{

    int row = matrix.size();
    int col = matrix[0].size();

    int count = 0;
    int traverseRow = 0;
    int traverseCol = 0;

    while (traverseCol < col || traverseRow < row)
    {
        string temp = "";
        if (traverseCol < col)
        {
            for (int i = 0; i < row; i++)
            {

                temp = matrix[i][traverseCol] + temp;
            }
            traverseCol++;
        }
        else
        {
            for (int i = 0; i < col; i++)
            {
                temp = matrix[traverseRow][i] + temp;
            }
            traverseRow++;
        }

        size_t found = temp.find(target);
        if (found != string::npos)
        {
            count++;
        }
        else{
            reverse(temp.begin(), temp.end());
            size_t found = temp.find(target);
            if (found != string::npos)
            {
            count++;
            }
        }
    }
    return count;
}

int main()
{
    // vector<vector<char > > vec = {
    //  {'B', 'B', 'M', 'B', 'B', 'B'},
    //  {'C', 'B', 'A', 'B', 'B', 'B'},
    //   {'I', 'B', 'G', 'B', 'B', 'B'}, 
    //  {'G', 'B', 'I', 'B', 'B', 'B'}, 
    //  {'A', 'B', 'C', 'B', 'B', 'B'}, 
    //  {'M', 'C', 'I', 'G', 'A', 'M'}};
// string t="MAGIC";

vector<vector<char > > vec = {
            {'D','D','D','G','D','D'},
            {'B','B','D','E','B','S'},
            {'B','S','K','E','B','K'},
            {'D','D','D','D','D','E'},
            {'D','D','D','D','D','E'},
            {'D','D','D','D','D','G'}
           };
        string t= "GEEKS";

    cout << countWord(vec, t) << endl;

    return 0;
}