/*
 * @lc app=leetcode id=2785 lang=cpp
 *
 * [2785] Sort Vowels in a String
 */

// @lc code=start
class Solution {
public:
    string sortVowels(string s) {
        int n = s.length();
        vector<char> vowels;
        vector<int> vowelIndices;
        
        for (int i = 0; i < n; i++) {
            if (strchr("aeiouAEIOU", s[i]) != nullptr) {
                vowels.push_back(s[i]);
                vowelIndices.push_back(i);
            }
        }
        
        if (vowels.empty()) {
            return s;
        }
        
        sort(vowels.begin(), vowels.end());
        
        string result = s;
        for (int i = 0; i < vowels.size(); i++) {
            result[vowelIndices[i]] = vowels[i];
        }
        
        return result;
    }
};
// @lc code=end

