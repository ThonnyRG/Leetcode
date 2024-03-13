class Solution {
  int pivotInteger(int n) {
    int num = n * (n + 1) ~/ 2;

    double x = num.isNaN ? double.nan : num.sqrt();

    if (x % 1 == 0) {
      return x.toInt();
    } else {
      return -1;
    }
  }
}
