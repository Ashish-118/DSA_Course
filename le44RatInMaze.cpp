#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void controller(string s, vector<int> info, int index, int x, int y, int h, int v, vector<vector<int>> maze, string output, vector<string> &ans, string history = " ")
{
    if (x == h && y == v)
    {
        ans.push_back(output);
        return;
    }
    if (index == s.size())
    {
     
        return;
    }

    int char_val = s[index] - 'A';
    vector<int>::iterator it;
    it = find(info.begin(), info.end(), char_val);
    int index_of_char = distance(info.begin(), it);

    if ((char_val == 17 || char_val == 11)) // R / L
    {
        if (0 <= (x + info[index_of_char + 1]) && (x + info[index_of_char + 1]) <= h)

        {

            if (maze[y][x + info[index_of_char + 1]])
            {
                string check = to_string(y) + to_string(x + info[index_of_char + 1]);
                int found = history.find(check);
                if (found == string::npos)
                {
                    output.push_back(s[index]);
                    history = history + to_string(y) + to_string(x) + " ";
                    controller(s, info, 0, x + info[index_of_char + 1], y, h, v, maze, output, ans,history);
                    output.pop_back();
                }
            }
        }
        index++;
    }
    else // U/D
    {
        if (0 <= (y + info[index_of_char + 1]) && (y + info[index_of_char + 1]) <= v)
        {

            if (maze[y + info[index_of_char + 1]][x])
            {
                string check = to_string(y + info[index_of_char + 1]) + to_string(x);
                int found = history.find(check);
                if (found == string::npos)
                {
                    output.push_back(s[index]);
                    history = history + to_string(y) + to_string(x) + " ";
                    controller(s, info, 0, x, y + info[index_of_char + 1], h, v, maze, output, ans,history);
                    output.pop_back();
                }
            }
        }
        index++;
    }
    controller(s, info, index, x, y, h, v, maze, output, ans,history);
}



int main()
{
    vector<int> info = {17, 1, 11, -1, 20, -1, 3, 1};

    string s = "RLUD";
    


    vector<string> ans;
    // vector<vector<int>> maze{{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<vector<int>> maze{{1,1,1,0,0}, {0,1,1,0,0}, {1,1,0,0,1}, {1,1,1,0,1},{0,1,1,1,1}};
    string output = "";
    
    // here v and h should be row-1 and col-1;
    controller(s, info, 0, 0, 0, 4, 4, maze, output, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}