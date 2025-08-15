/*
 * @lc app=leetcode id=2264 lang=cpp
 *
 * [2264] Largest 3-Same-Digit Number in String
 */

// @lc code=start

// class Solution {
//     public String largestGoodInteger(String num) {
//          if (num.length() <= 1)
//             return "";

//         Map<Integer, String> stringMap = new HashMap<>();

//         for (int i = 0; i < num.length() - 2; i++) {
//             if (num.charAt(i) == num.charAt(i + 2) && num.charAt(i) == num.charAt(i + 1))
//                 stringMap.putIfAbsent(num.charAt(i) - '0', num.substring(i, i + 3));
//         }

//         for (int i = 9; i >=0; i--)
//             if (stringMap.containsKey(i))
//                 return stringMap.get(i);

//         return "";
//     }
// }


class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();

        if (n <= 1)
        {
            return "";
        }

        unordered_map<int, string> stringMap;

        for (int i = 0; i < n - 2; i++)
        {
            if (num[i] == num[i + 2] && num[i] == num[i + 1])
            {
                int digit = num[i] - '0';
                if (stringMap.find(digit) == stringMap.end())
                {
                    stringMap[digit] = num.substr(i, 3);
                }
                
            }
            
        }
        
        for (int i = 9; i >= 0; i--)
        {
            if(stringMap.find(i) != stringMap.end()){
                return stringMap[i];
            }
        }
        return "";
    }
};
// @lc code=end

