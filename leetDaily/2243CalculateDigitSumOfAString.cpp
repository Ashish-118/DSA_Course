class Solution {
public:
    string digitSum(string s, int k) {
      

        while (s.length() > k) {
            string temp = "";
            int len = 0;
            int sum = 0;
            int n = s.length();

            for (int i = 0; i < n; i++) {
                sum += s[i] - '0';
                len++;
                if (i==n-1 || len == k) {
                    temp+=to_string(sum);
                    len=0;
                    sum=0;
                }
            }
            s=temp;
        }

        return s;
    }
};