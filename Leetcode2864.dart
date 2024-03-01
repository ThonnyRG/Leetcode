import 'dart:io';

class Solution {
  String maximumOddBinaryNumber(String s) {
    String returnString = "";
    String count1 = "";
    String count0 = "";
    if (1 <= s.length && s.length <= 100) {
        for (int i = 0; i < s.length; i++) {
        if (s[i] == '0')
            count0 += "0";
        if (s[i] == '1') count1 += "1";
        }
        if (!(count1.isEmpty) && count1.length + count0.length == s.length) {
        returnString = count1.substring(1) + count0 + "1";
        }
    }
    return returnString;
    }
}