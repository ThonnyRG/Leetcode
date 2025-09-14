/*
 * @lc app=leetcode id=966 lang=cpp
 *
 * [966] Vowel Spellchecker
 */

// @lc code=start
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactWords(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitiveMap;
        unordered_map<string, string> vowelPatternMap;

        auto replaceVowels = [](const string& word){
            string pattern;
            for (char c : word)
            {
             if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
             {
                pattern += '*';
             } else{
                pattern += c;
             }
            }
            return pattern;
        };
        for(const auto& word : wordlist)
        {
            string lowercaseWord = word;
            transform(lowercaseWord.begin(), lowercaseWord.end(), lowercaseWord.begin(), ::tolower);

            if (!caseInsensitiveMap.count(lowercaseWord))
            {
                caseInsensitiveMap[lowercaseWord] = word;
            }

            string vowelPattern = replaceVowels(lowercaseWord);
            if(!vowelPatternMap.count(vowelPattern)){
                vowelPatternMap[vowelPattern] = word;
            }

            
        }

        vector<string> result;
        for (auto& query: queries)
        {
            if (exactWords.count(query))
            {
                result.emplace_back(query);
                continue;
            }

            string lowercaseQuery = query;
            transform(lowercaseQuery.begin(), lowercaseQuery.end(), lowercaseQuery.begin(), ::tolower);

            if(caseInsensitiveMap.count(lowercaseQuery)){
                result.emplace_back(caseInsensitiveMap[lowercaseQuery]);
                continue;
            }

            string queryPattern = replaceVowels(lowercaseQuery);
            if(vowelPatternMap.count(queryPattern)){
                result.emplace_back(vowelPatternMap[queryPattern]);
                continue;
            }
            result.emplace_back("");
            
        }
        
        return result;
        
    }
};
// @lc code=end

