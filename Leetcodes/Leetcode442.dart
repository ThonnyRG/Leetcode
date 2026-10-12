/*

class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            int x = Math.abs(nums[i]);
            if (nums[x - 1] < 0) {
                ans.add(x);
            }
            nums[x - 1] *= -1;
        }
        return ans;
    }
}

*/

class Solution {
  List<int> findDuplicates(List<int> nums) {
    List<int> duplicates = [];
    int n = nums.length;
    for(int i = 0; i < n; i++){
      int x = (nums[i]).abs();
        if(nums[x - 1] < 0){
          duplicates.add(x);
        }
        nums[x - 1] *= -1;
    }
    return duplicates;
  }
}

void compare(List<int> compare, List<int> answer){
  Solution solution = Solution();
  List<int> res = solution.findDuplicates(compare);

  if(res != answer){
    print("[x] failed");
  }else{
    print("[✔] pass");
  }

}


void main(){
  List<int> t1 = [4,3,2,7,8,2,3,1];
  List<int> t2 = [1,1,2];
  List<int> t3 =[1];

  List<int> a1 = [4,3,2,7,8,2,3,1];
  List<int> a2 = [1,1,2];
  List<int> a3 = [1];

  compare(t1, a1);
  compare(t2, a2);
  compare(t3, a3);
}