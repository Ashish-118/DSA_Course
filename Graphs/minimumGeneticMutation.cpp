class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {

        queue<pair<string, int>> q;
        unordered_map<string, bool> m;

        // mark all genes in bank as unvisited
        for (auto &x : bank)
        {
            m[x] = false;
        }

        // if endGene not in bank → impossible
        if (!m.count(endGene))
            return -1;

        q.push({startGene, 0});
        m[startGene] = true; // mark start as visited

        while (!q.empty())
        {
            auto front = q.front();
            string node = front.first;
            q.pop();
            int lvl = front.second;

            if (node == endGene)
                return lvl;

            string dup = node;

            for (int i = 0; i < node.length(); i++)
            {
                char original = node[i];

                for (auto l : {'A', 'C', 'G', 'T'})
                {
                    node[i] = l;
                    if (node != dup && m.count(node) && !m[node])
                    {
                        q.push({node, lvl + 1});
                        m[node] = true;
                        cout << node << endl;
                    }
                }

                node[i] = original; // restore original character
            }
        }

        return -1;
    }
};
