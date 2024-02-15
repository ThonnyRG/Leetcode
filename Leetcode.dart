class Solution {
  String? firstPalindrome(List<String> words) {
    for (String word in words) {
      if (isPalindrome(word)) {
        return word;
      }
    }
    return "";
  }

  bool isPalindrome(String s) {
    int i = 0;
    int j = s.length - 1;
    while (i < j) {
      if (s[i++] != s[j--]) {
        return false;
      }
    }
    return true;
  }
}



void main(){
  var case1 = ["abc","car","ada","racecar","cool"];
  //Output: "ada"
  var case2 = ["notapalindrome","racecar"];
  //Output: "racecar"
  var case3 = ["def","ghi"];
  //Output: ""

  print(Solution().firstPalindrome(case1));
  print(Solution().firstPalindrome(case2));
  print(Solution().firstPalindrome(case3));
}