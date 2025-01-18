// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int> &ratings)
{
    int lenR = ratings.size();

    vector<int> Icandy(lenR, 1);
    int total_candy = lenR;

    bool visited = false;

    while (true)
    {
        for (int i = 0; i < lenR; i++)
        {
            cout << "total_cady inside loop i->" << i << " " << total_candy << endl;
            int j = (i > 0 ? i : 0);

            if (ratings[j] > ratings[j + 1])
            {

                while (Icandy[j] < Icandy[j + 1])
                {
                    Icandy[j]++;
                    total_candy++;

                    visited = true;
                }
            }
            else if (ratings[j] < ratings[j + 1])
            {

                while (Icandy[j] > Icandy[j + 1])
                {
                    Icandy[j + 1]++;
                    total_candy++;
                    visited = true;
                }
            }
        }
        cout << "total candy " << total_candy << endl;
        if (!visited)
        {
            break;
        }
        else
        {
            visited = false;
        }
    }
    return total_candy;
}

int main()
{
    vector<int> v = {1, 2, 87, 87, 87, 2, 1};
    cout << "total in main " << candy(v);

    return 0;
}