class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if (k == 1)
            return r - l + 1;

        int a1 = 0, a2 = 0;

        for (int i = 0; i <=r ; i++) {
            if (pow(i,k) <= r)
                a1++;
            else break;
        }

        for (int i = 0; i <=l-1 ; i++) {
            
            if (pow(i,k)<= l-1)
                a2++;

            else break;
        }

        

        return a1-a2;
    }
};


///

class Solution
{
public:
    int countKthRoots(int l, int r, int k)
    {
        if (k == 1)
            return r - l + 1;

        int a1 = 0, a2 = 0;

        for (int i = 0; i <= r; i++)
        {
            if (pow(i, k) <= l - 1)
                a2++;

            if (pow(i, k) <= r)
                a1++;
            else
                break;
        }

        // for (int i = 0; i <= l - 1; i++) {

        //     else break;
        // }

        return a1 - a2;
    }
};