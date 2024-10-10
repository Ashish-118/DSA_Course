#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(vector<string> &ans, string dup, string output, string given_word, int index, int j)
{

    if (index >= given_word.length())
    {   
        ans.push_back(output);
        return;
    }

    if (index != 0)
    {
        dup.erase(j, 1);
    }

    for (int i = 0; i < dup.length(); i++)
    {
        output.push_back(dup[i]);
        solve(ans, dup, output, given_word, index + 1, i);
        output.pop_back();
    }
}

int main()
{
    vector<string> ans;
    string word = "ash";
    string output = "";
    int i = 0;
    solve(ans, word, output, word, 0, 0);
    for (; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout <<"\n\n\n\n\n\n\n"<< "Total is" << i << endl;
    return 0;
}