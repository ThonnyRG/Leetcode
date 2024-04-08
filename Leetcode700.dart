class Solution {
  int countStudents(List<int> students, List<int> sandwiches) {
    int ones = 0; // count of students who prefer type1
    int zeros = 0; // count of students who prefer type0

    for (var stud in students) {
      if (stud == 0)
        zeros++;
      else
        ones++;
    }

    // for each sandwich in sandwiches
    for (var sandwich in sandwiches) {
      if (sandwich == 0) {
        // if sandwich is of type0
        if (zeros == 0) {
          // if no student wants a type0 sandwich
          return ones;
        }
        zeros--;
      } else {
        // if sandwich is of type1
        if (ones == 0) {
          // if no student wants a type1 sandwich
          return zeros;
        }
        ones--;
      }
    }
    return 0;
  }
}
