/* The functions which
builds the segment tree */

void buildTree(int seg[], int i, int l, int r, int arr[])
{
    if (l == r)
    {
        seg[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;

    buildTree(seg, 2 * i + 1, l, mid, arr);
    buildTree(seg, 2 * i + 2, mid + 1, r, arr);

    seg[i] = min(seg[2 * i + 1], seg[2 * i + 2]);
}
int *constructST(int arr[], int n)
{
    // Your code here

    int *seg = new int[4 * n];

    buildTree(seg, 0, 0, n - 1, arr);

    return seg;
}

/* The functions returns the
 min element in the range
 from a and b */

int getQuery(int start, int end, int i, int l, int r, int *seg)
{
    if (l > end || r < start)
        return INT_MAX;
    else if (l >= start && r <= end)
        return seg[i];

    int mid = l + (r - l) / 2;

    int v1 = getQuery(start, end, 2 * i + 1, l, mid, seg);
    int v2 = getQuery(start, end, 2 * i + 2, mid + 1, r, seg);

    return min(v1, v2);
}
int RMQ(int st[], int n, int a, int b)
{

    return getQuery(a, b, 0, 0, n - 1, st);
}