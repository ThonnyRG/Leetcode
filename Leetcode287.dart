class Solution {
  int findDuplicate(List<int> nums) {
    Set<int> set = {};
    for (int num in nums) {
      if (set.contains(num)) {
        return num;
      }
      set.add(num);
    }
    return -1;
  }
}

void main() {
  var list1 = [1, 3, 4, 2, 2];
  var list2 = [3, 1, 3, 4, 2];
  var list3 = [3, 3, 3, 3, 3];

  int res1 = 2;
  int res2 = 3;
  int res3 = 3;

  Solution solution = Solution(); // Crear una instancia de Solution

  int ans1 = solution.findDuplicate(list1); // Llamar al método en la instancia
  int ans2 = solution.findDuplicate(list2);
  int ans3 = solution.findDuplicate(list3);

  checkResult(ans1, res1);
  checkResult(ans2, res2);
  checkResult(ans3, res3);
}

void checkResult(int ans, int res) {
  if (ans != res) {
    print("Not pass");
  } else {
    print("Pass");
  }
}
