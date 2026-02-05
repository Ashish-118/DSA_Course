class MyCalendarThree
{
public:
    map<int, int> events;

    MyCalendarThree()
    {
    }

    int book(int startTime, int endTime)
    {
        events[startTime] += 1;
        events[endTime] += -1;

        int maxi = 0;
        int curr = 0;

        for (auto e : events)
        {
            curr += e.second;
            maxi = max(maxi, curr);
        }

        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */