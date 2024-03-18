import 'dart:math';

class Solution {
  int findMinArrowShots(List<List<int>> points) {
    points.sort((a, b) {
      if (a[0] == b[0]) {
        return a[1].compareTo(b[1]);
      }
      return a[0].compareTo(b[0]);
    });

    int count = 0;
    int prevlast = points[0][1];

    for (int i = 1; i < points.length; i++) {
      if (prevlast >= points[i][0]) {
        if (prevlast > points[i][1]) {
          prevlast = points[i][1];
        }
      } else {
        prevlast = points[i][1];
        count++;
      }
    }

    return count + 1;
  }
}
