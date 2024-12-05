// path compression

int find(int x)
{
    if (p[x] == x)
        return x;
    p[x] = find(p[x]);
    return p[x];
}