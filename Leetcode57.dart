class Solution {
  List<List<int>> insert(List<List<int>> intervals, List<int> newInterval) {
    List<List<int>> result = [];
    
    // Iterate through intervals and add non-overlapping intervals before newInterval
    int i = 0;
    while (i < intervals.length && intervals[i][1] < newInterval[0]) {
      result.add(List<int>.from(intervals[i]));
      i++;
    }
    
    // Merge overlapping intervals
    while (i < intervals.length && intervals[i][0] <= newInterval[1]) {
      newInterval[0] = newInterval[0] < intervals[i][0] ? newInterval[0] : intervals[i][0];
      newInterval[1] = newInterval[1] > intervals[i][1] ? newInterval[1] : intervals[i][1];
      i++;
    }
    
    // Add merged newInterval
    result.add(List<int>.from(newInterval));
    
    // Add non-overlapping intervals after newInterval
    while (i < intervals.length) {
      result.add(List<int>.from(intervals[i]));
      i++;
    }
    
    return result;
  }
}
