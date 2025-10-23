// Time Complexity : O(2^N * N^2).
// Notice the while loop that performs the BFS traversal of the graph.
// In the worst case, the while loop can run 2^N iterations, where N is the number of nodes in the graph.
// This is because the program explores all possible combinations of nodes using bit masking i.e. each bit can be either 0 or 1 (2 possibilities) —-> 2^N
// Within each iteration, there is a nested loop that iterates through the neighbors of the current node.
// In the worst case, this inner loop iterates N times for each node.
// So, the overall time complexity is 0(2^N * N^2).
/********************************************************* C++ *******************************************************/
class Solution
{
public:
    typedef pair<int, int> P;

    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size();

        if (n == 1 || n == 0)
            return 0;

        queue<P> que;

        set<P> vis;
        // Instead of set, you can also use : vector<vector<bool>> visited(n, vector<bool>(finalState, false));
        // Just like done in Java code below

        int allVisitedState = (1 << n) - 1; // if all nodes visited then

        for (int i = 0; i < n; i++)
        {
            int maskValue = (1 << i);

            que.push({i, maskValue});

            vis.insert({i, maskValue});
        }

        int result = 0;

        // Implementing BFS
        while (!que.empty())
        {

            int N = que.size();
            result++;
            while (N--)
            {

                auto curr = que.front();
                que.pop();

                int currNode = curr.first;
                int currMask = curr.second;

                for (auto &adj : graph[currNode])
                {
                    int nextMask = currMask | (1 << adj);

                    if (nextMask == allVisitedState)
                        return result;

                    if (vis.find({adj, nextMask}) == vis.end())
                    {
                        vis.insert({adj, nextMask});
                        que.push({adj, nextMask});
                    }
                }
            }
        }

        return -1;
    }
};