class Solution {
  void swap(List<int> arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }

  int firstMissingPositive(List<int> nums) {
    int n = nums.length;

    for (int i = 0; i < n; i++) {
      while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
        swap(nums, i, nums[i] - 1);
      }
    }

    for (int i = 0; i < n; i++) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }

    return n + 1;
  }
}

void test(List<int> compare, int answer){
  Solution solution = Solution();
  int res = solution.firstMissingPositive(compare);

  if(res != answer){
    print("[x] failed");
  }else{
    print("[✔] pass");
  }
}

void main() {
  Solution solution = Solution();

  var nums1 = [1, 2, 0];
  var nums2 = [3, 4, -1, 1];
  var nums3 = [7, 8, 9, 11, 12];

  int a1 = 3;
  int a2 = 2;
  int a3 = 1;

  test(nums1, a1);
  test(nums2, a2); 
  test(nums3, a3); 
}