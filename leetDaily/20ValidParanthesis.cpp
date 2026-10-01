class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char, char> mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';

   
        for (int i = 0; i < s.length(); i++) {
            char x = s[i];
            if (x == '(' || x == '{' || x == '[') {
                st.push(x);
            } else {
                if (!st.empty() && x == mp[st.top()]) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};