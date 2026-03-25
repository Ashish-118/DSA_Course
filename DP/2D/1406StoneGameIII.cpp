class Solution {
public:
  int t[50001][2];
  int solve(int i, vector<int> &stoneValue, int player) {
    if (i >= stoneValue.size())
      return 0;

    if (t[i][player] != -1)
      return t[i][player];

    int toReturn = -1;

    if (player) {
      int maxVal = INT_MIN;
      int sum = 0;

      for (int j = 0; j < 3; j++) {
        if (j + i >= stoneValue.size())
          break;
        sum += stoneValue[j + i];
        maxVal = max(maxVal, sum + solve(j + i + 1, stoneValue, 0));
      }

      toReturn = maxVal;
    } else {
      int minVal = INT_MAX;

      for (int j = 0; j < 3; j++) {
        if (j + i >= stoneValue.size())
          break;

        minVal = min(minVal, solve(j + i + 1, stoneValue, 1));
      }

      toReturn = minVal;
    }

    return t[i][player] = toReturn;
  }

  string stoneGameIII(vector<int> &stoneValue) {
    memset(t, -1, sizeof(t));
    int sum = accumulate(begin(stoneValue), end(stoneValue), 0);
    int aliceMax = solve(0, stoneValue, 1);

    string ans = "";
    if (aliceMax > sum - aliceMax)
      ans = "Alice";
    else if (aliceMax < sum - aliceMax)
      ans = "Bob";
    else
      ans = "Tie";

    return ans;
  }
};