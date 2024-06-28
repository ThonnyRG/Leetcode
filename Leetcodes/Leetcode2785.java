class Solution {
    public long maximumImportance(int n, int[][] roads) {
      var degrees = new long[n];
      var sum = 0L;
  
      for (var road : roads) {
        degrees[road[0]]++;
        degrees[road[1]]++;
      }
      Arrays.sort(degrees);
  
      for (var i=0; i<n; i++)
        sum += degrees[i] * (i+1);
  
      return sum;
    }
  }