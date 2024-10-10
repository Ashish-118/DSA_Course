#include <bits/stdc++.h>

int findMinimumCost(string str) {
  stack<char> st;
  int step = 0;
  if (str.length() % 2 == 0) {
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == '{') {
        if (i == str.length() - 1) {
          str[i] == '}';
          step++;
        } else {
          st.push(str[i]);
        }
      }
      if (str[i] == '}') {
        if (st.empty()) {
          str[i] = '{';
          st.push(str[i]);
          step++;
        } else {
          st.pop();
        }
      }
    }

    if (~st.empty()) {
      step += st.size() / 2;
    }
  } else {
    return -1;
  }
  return step;
}