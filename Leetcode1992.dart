class Solution {
List<List<int>> findFarmland(List<List<int>> land) {
  List<List<int>> output = [];
  
  void farmer(int i, int j, List<int> arr) {
    if (i < 0 || j < 0 || i > land.length - 1 || j > land[0].length - 1 || land[i][j] != 1) return;
    land[i][j] = 0;
    
    if (i < arr[0]) arr[0] = i;
    if (j < arr[1]) arr[1] = j;
    if (i > arr[2]) arr[2] = i;
    if (j > arr[3]) arr[3] = j;
    
    farmer(i + 1, j, arr);
    farmer(i - 1, j, arr);
    farmer(i, j + 1, arr);
    farmer(i, j - 1, arr);
  }
  
  for (int i = 0; i < land.length; i++) {
    for (int j = 0; j < land[0].length; j++) {
      if (land[i][j] == 1) {
        List<int> arr = [i, j, i, j];
        farmer(i, j, arr);
        output.add(arr);
      }
    }
  }
  
  return output;
}

}