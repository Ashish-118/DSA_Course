/*
-----------------------------------------------
BRUTE FORCE (BFS) APPROACH

We track:

    z = number of zeros in the string

Each operation flips exactly k bits.

If we flip:
    f zeros  -> become ones
    k-f ones -> become zeros

So new number of zeros becomes:

    newZ = z - f + (k - f)
         = z + k - 2f


-----------------------------------------------
VALID RANGE OF f

We cannot flip more zeros than we have:
    f <= z

We cannot flip more ones than exist:
    k - f <= (n - z)
    => f >= k - (n - z)

So:

    minF = max(0, k - (n - z))
    maxF = min(k, z)


-----------------------------------------------
WHY BFS ?

We want MINIMUM operations → BFS is ideal.

Each state represents a possible number of zeros.

    operations[z] = min steps needed to reach z zeros

We avoid revisiting states using:

    if (operations[newZ] == -1)


-----------------------------------------------
IMPORTANT QUESTION:

If we don't revisit z again,
why is time complexity still O(n * k) ?


-----------------------------------------------
ANSWER:

Total possible states of z:

    z ∈ [0 … n]
    => O(n) states


Each state is processed only once ✔


BUT for each state we run:

    for f in [minF ... maxF]

Worst case:

    minF = 0
    maxF = k

So loop runs O(k) times.


Even when newZ is already visited:

    operations[newZ] != -1

we SKIP pushing into queue ✔
BUT we still CHECK it ❗


Example:

for (int f = minF; f <= maxF; f++) {
    int newZ = z + k - 2*f;

    // we still compute newZ
    // we still check operations[newZ]

    if (operations[newZ] == -1) {
        ...
    }
}


So inner loop still runs fully.


-----------------------------------------------
TOTAL WORK

Number of states      = O(n)
Work per state        = O(k)

Therefore:

    Time Complexity = O(n * k)


Even though BFS prevents revisiting states,
it does NOT prevent running the transition loop.


-----------------------------------------------
*/
class Solution
{
public:
    int minOperations(string s, int k)
    {
        int n = s.length();

        int startZeros = 0;
        for (char ch : s)
            if (ch == '0')
                startZeros++;

        if (startZeros == 0)
            return 0;

        vector<int> operations(n + 1, -1);
        queue<int> q;

        q.push(startZeros);
        operations[startZeros] = 0;

        while (!q.empty())
        {
            int z = q.front();
            q.pop();

            int minF = max(0, k - (n - z));
            int maxF = min(k, z);

            for (int f = minF; f <= maxF; f++)
            {
                int newZ = z + k - 2 * f;

                if (operations[newZ] == -1)
                {
                    operations[newZ] = operations[z] + 1;

                    if (newZ == 0)
                        return operations[newZ];

                    q.push(newZ);
                }
            }
        }

        return -1;
    }
};

// optimal approach

// Approach-2 - Optimal - Skipping already visited states
// T.C : O(n*logn)
// S.C : O(n)
class Solution
{
public:
    int minOperations(string s, int k)
    {
        int n = s.length();

        int startZeros = 0;
        for (char &ch : s)
        {
            if (ch == '0')
                startZeros++;
        }

        if (startZeros == 0)
        {
            return 0; // no operations required
        }

        vector<int> operations(n + 1, -1);
        // operations[z] = min operations required to reach state in which we have z 0s

        set<int> evenSet;
        set<int> oddSet;

        for (int count = 0; count <= n; count++)
        {
            if (count % 2 == 0)
            {
                evenSet.insert(count);
            }
            else
            {
                oddSet.insert(count);
            }
        }

        queue<int> que;
        que.push(startZeros);
        operations[startZeros] = 0;
        if (startZeros % 2 == 0)
        {
            evenSet.erase(startZeros);
        }
        else
        {
            oddSet.erase(startZeros);
        }

        while (!que.empty())
        {
            int z = que.front();
            que.pop();

            int min_new_z = z + k - 2 * min(k, z);
            int max_new_z = z + k - 2 * max(0, k - n + z);

            set<int> &currSet = (min_new_z % 2 == 0) ? evenSet : oddSet;

            auto it = currSet.lower_bound(min_new_z);

            while (it != currSet.end() && *it <= max_new_z)
            {
                int newZ = *it;

                if (operations[newZ] == -1)
                {
                    operations[newZ] = operations[z] + 1;

                    if (newZ == 0)
                    {
                        return operations[newZ];
                    }

                    que.push(newZ);
                }

                it = currSet.erase(it);
            }
        }

        return -1;
    }
};
