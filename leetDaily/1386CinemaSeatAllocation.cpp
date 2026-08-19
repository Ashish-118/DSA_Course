class Solution
{
public
    int maxNumberOfFamilies(int n, int[][] reservedSeats)
    {
        HashMap<Integer, HashSet<Integer>> mp = new HashMap<>();

        for (int[] e : reservedSeats)
        {
            mp.computeIfAbsent(e[0], k->new HashSet<>()).add(e[1]);
        }

        int total = n * 2;

        for (int key : mp.keySet())
        {
            HashSet<Integer> s = mp.get(key);
            total -= 2;

            int notUse = 0;
            for (int x : new int[]{2, 4, 6})
            {
                int e = x;
                int steps = 0;

                while (notUse != e && !s.contains(e) && steps < 4)
                {
                    e++;
                    steps++;
                }

                if (steps == 4)
                {
                    notUse = x + 2;
                    total += 1;
                }
            }
        }

        return total;
    }
}