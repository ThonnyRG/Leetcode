class Solution {
  String minRemoveToMakeValid(String s) {
    // Convert input string to list for easier manipulation
    List<String> arr = s.split('');

    // Initialize variables
    int openParenthesesCount = 0;

    // First pass: mark excess closing parentheses with '*'
    for (int i = 0; i < arr.length; i++) {
      if (arr[i] == '(') {
        openParenthesesCount++;
      } else if (arr[i] == ')') {
        if (openParenthesesCount == 0) {
          arr[i] = '*'; // Mark excess closing parentheses
        } else {
          openParenthesesCount--;
        }
      }
    }

    // Second pass: mark excess opening parentheses from the end
    for (int i = arr.length - 1; i >= 0; i--) {
      if (openParenthesesCount > 0 && arr[i] == '(') {
        arr[i] = '*'; // Mark excess opening parentheses
        openParenthesesCount--;
      }
    }

    // Filter out marked characters
    arr.removeWhere((char) => char == '*');

    // Construct the result string from the filtered list
    return arr.join();
  }
}
