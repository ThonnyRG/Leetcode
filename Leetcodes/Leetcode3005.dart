class Solution {
  int maxFrequencyElements(List<int> nums) {
    List<int> a = List<int>.filled(101, 0);
    for (int i in nums) {
      a[i]++;
    }
    int maxi = 0;
    for (int i = 0; i <= 100; i++) {
      maxi = maxi > a[i] ? maxi : a[i];
    }
    int ans = 0;
    for (int i = 0; i <= 100; i++) {
      if (a[i] == maxi) {
        ans += maxi;
      }
    }
    return ans;
  }
}
