class Solution {
  String customSortString(String order, String s) {
    Map<String, int> mp = {};
    for (var i = 0; i < s.length; i++) {
      mp[s[i]] = (mp[s[i]] ?? 0) + 1;
    }

    StringBuffer ans = StringBuffer();

    for (var i = 0; i < order.length; i++) {
      if (mp.containsKey(order[i])) {
        for (var j = 0; j < mp[order[i]]!; j++) {
          ans.write(order[i]);
        }
        mp[order[i]] = 0;
      }
    }

    mp.forEach((key, value) {
      if (value != 0) {
        for (var j = 0; j < value; j++) {
          ans.write(key);
        }
      }
    });

    return ans.toString();
  }
}
