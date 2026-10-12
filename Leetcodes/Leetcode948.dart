import 'dart:core';

class Solution {
  int bagOfTokensScore(List<int> tokens, int power) {
    tokens.sort();
    int s = 0;
    int maxi = 0;
    int l = 0, r = tokens.length - 1;

    while (l <= r) {
      if (power >= tokens[l]) {
        power -= tokens[l];
        s++;
        l++;
        maxi = s > maxi ? s : maxi;
      } else if (s > 0) {
        power += tokens[r];
        s--;
        r--;
      } else {
        break;
      }
    }

    return maxi;
  }
}
