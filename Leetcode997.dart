

class Solution {
  int findJudge(int n, List<List<int>> trust) {
    List<int> trusting = List.filled(n + 1, 0);
    List<int> trusted = List.filled(n + 1, 0);

    for (int i = 0; i < trust.length; i++) {
      trusting[trust[i][0]]++;
      trusted[trust[i][1]]++;
    }

    int ans = -1;

    for (int i = 1; i <= n; i++) {
      if (trusting[i] == 0 && trusted[i] == n - 1)
        ans = i;
    }

    return ans;
  }
}
