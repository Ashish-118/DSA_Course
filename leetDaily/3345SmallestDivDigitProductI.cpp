class Solution {
public:
    int smallestNumber(int n, int t) {
        
        while (true) {

            int mul = 1;
            int temp = n;

            while (temp != 0) {
                mul *= (temp % 10);

                temp /= 10;
            }

            if (mul % t == 0)
                return n;

            n++;
        }
    }
};