/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1 = split(version1, '.');
        vector<string> v2 = split(version2, '.');
        
        for (int i = 0; i < max(v1.size(), v2.size()); i++) {
            int num1 = i < v1.size() ? stoi(v1[i]) : 0;
            int num2 = i < v2.size() ? stoi(v2[i]) : 0;
            
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }
        
        return 0;
    }

private:
    vector<string> split(string str, char delimiter) {
        vector<string> result;
        stringstream ss(str);
        string item;
        
        while (getline(ss, item, delimiter)) {
            result.push_back(item);
        }
        
        return result;
    }
};
// @lc code=end

