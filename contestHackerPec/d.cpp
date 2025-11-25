#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int a, n;
    cin >> a >> n;

    vector<int> sleep(n);
    vector<int> score(n);
    vector<int> time(n);

    for (int i = 0; i < n; i++)
    {
        cin >> sleep[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> score[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> time[i];
    }
    int d;
    cin >> d;
    int totalScore = 0;
    int totalTime = a + d;

    for (int i = 0; i < n; i++)
    {
        totalTime -= sleep[i];
        if (totalTime >= time[i])
        {
            totalScore += score[i];
            totalTime -= time[i];
        }
    }
    cout << totalScore << endl;

    return 0;
}