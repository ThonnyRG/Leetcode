
class Solution {
  bool isIsomorphic(String s, String t) {
    List<int> map1 = List.filled(200, 0);
    List<int> map2 = List.filled(200, 0);

    if (s.length != t.length) return false;

    for (int i = 0; i < s.length; i++) {
      if (map1[s.codeUnitAt(i)] != map2[t.codeUnitAt(i)]) return false;

      map1[s.codeUnitAt(i)] = i + 1;
      map2[t.codeUnitAt(i)] = i + 1;
    }
    return true;
  }
}



void check(int n, bool output, bool result){
  if(output != result){
    print("test:" + n.toString() + "[X] not passed");
  }else{
    print("test:" + n.toString() + "[✔] passed");
  }

}
void main(){

  //case 1
  String s1 = "egg";
  String t1 = "add";
  bool r1 = true;
  //case 2
  String s2 = "foo";
  String t2 = "bar";
  bool r2 = false;

  //case 3
  String s3 = "paper";
  String t3 = "title";
  bool r3 = true;

  check(1, r1, Solution().isIsomorphic(s1,t1));
  check(2, r2, Solution().isIsomorphic(s2,t2));
  check(3, r3, Solution().isIsomorphic(s3,t3));

}