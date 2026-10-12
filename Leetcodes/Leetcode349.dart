class Solution {
  List<int> intersection(List<int> nums1, List<int> nums2) {
    Set<int> s1 = Set<int>.from(nums1);
    Set<int> s2 = Set<int>();

    for (int i in nums2) {
      if (s1.contains(i)) s2.add(i);
    }

    return s2.toList();
  }
}
