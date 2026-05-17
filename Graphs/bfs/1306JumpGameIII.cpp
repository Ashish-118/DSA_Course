class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {

        if (find(arr.begin(), arr.end(), 0) == arr.end())
        {
            return false;
        }

        queue<int> q;
        q.push(start);
        int n = arr.size();
        vector<bool> visited(n, false);
        visited[start] = true;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            if (arr[front] == 0)
                return true;

            if (arr[front] + front < n && !visited[arr[front] + front])
            {
                q.push(arr[front] + front);
                visited[arr[front] + front] = true;
            }
            if (front - arr[front] >= 0 && !visited[front - arr[front]])
            {
                q.push(front - arr[front]);
                visited[front - arr[front]] = true;
            }
        }

        return false;
    }
};