class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {

        map<int, int> roomCount;
        vector<int> statusOfRoom(n, 0);
        int j = 0;
        int t = -1;
        while (j < meetings.size())
        {
            int index = -1;
            int minTime = INT_MAX;

            for (int i = 0; i < n; i++)
            {
                if ((t + statusOfRoom[i]) < minTime)
                {
                    index = i;
                    minTime = t + statusOfRoom[i];
                }
            }

            t = (t == -1 ? meetings[0][0] : minTime + 1);

            int durationToMinus = statusOfRoom[index];
            for (int i = 0; i < n; i++)
            {
                statusOfRoom[i] -= (durationToMinus + 1);
            }

            for (int i = 0; i < n; i++)
            {
                if (statusOfRoom[i] <= 0)
                {

                    if (j < meetings.size())
                    {
                        statusOfRoom[i] = abs(meetings[j][1] - meetings[j][0]) - 1;
                        roomCount[i]++;
                        j++;
                    }
                }
            }
        }

        int max = INT_MIN;
        int ansINDEX = -1;
        for (int i = 0; i < n; i++)
        {
            if (roomCount[i] > max)
            {
                ansINDEX = i;
                max = roomCount[i];
            }
        }

        return ansINDEX;
    }
}; // 57/81 test cases passed
// The code above is a solution to the problem of finding the most booked meeting room.
// it works  to optimally allot meeting rooms so that meetings can start as soon as possible.