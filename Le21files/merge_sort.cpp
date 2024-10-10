#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_sort(vector<int> v1, vector<int> v2)
{
    vector<int> v3;
 int i=0, j=0,g=0;
    // for (int i = 0; i < v1.size(); i++)
    // {
    //     for (int j = g; j < v2.size(); j++)
    //     {
    //         if (v2[j]<v1[i])
    //         {
    //          v3.push_back(v2[j]);
    //          g++;
    //         }
    //         else{
    //          v3.push_back(v1[i]);
    //          break;

    //         }

    //     }
    // }

    while (i<(v1.size()) && j<(v2.size()))
    {
        if (v2[j] < v1[i])
        {
            v3.push_back(v2[j]);
            j++;
   
            
        }
        else
        {
            v3.push_back(v1[i]);
            i++;
            break;
        }
   
      
    }
cout<<"g ki value "<<j<<endl;

    if (g != (v2.size() - 1))
    {
        for (int x = g; x < v2.size() - 1; x++)
        {
            v3.push_back(v2[x]);
        }
    }

    v3.push_back(max(v1[v1.size() - 1], v2[v2.size() - 1]));
    return v3;
}

void display(vector<int> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
}

int main()
{
    vector<int> arr1, arr2;

    arr1.push_back(2);
    arr1.push_back(5);
    arr1.push_back(9);
    arr1.push_back(11);
    arr1.push_back(14);
    arr1.push_back(17);
    arr1.push_back(19);
    arr1.push_back(23);
    arr1.push_back(27);

    arr2.push_back(4);

    arr2.push_back(10);
    arr2.push_back(12);

    arr2.push_back(15);
    arr2.push_back(21);

    vector<int> ans = merge_sort(arr1, arr2);
    display(ans);

    return 0;
}