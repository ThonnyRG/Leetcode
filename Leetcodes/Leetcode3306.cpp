class Solution {
    public:
        bool isVowel(char ch){
            return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u');
        }
    
        long long countOfSubstrings(string word, int k) {
            unordered_map<char,int> mp;
            long long ans = 0;
    
            int n = word.size();
            vector<int> pre(n , 0);
    
            if(!isVowel(word[0])){
                pre[0] = 1;
            }
    
            for(int i=1;i<n;i++){
                if(!isVowel(word[i])){
                    pre[i] = pre[i-1] + 1;
                }else{
                    pre[i] = pre[i-1];
                }
            }
            int i = 0;
            int j = 0;
    
            int cntk = 0;
    
            while(j < n){
                if(isVowel(word[j])){
                    mp[word[j]]++;
                }else{
                    cntk++;
                }
    
                while(cntk > k){
                    if(isVowel(word[i])){
                        mp[word[i]]--;
                        if(mp[word[i]] == 0){
                            mp.erase(word[i]);
                        }
                    }else{
                        cntk--;
                    }
                    i++;
                }
    
                while(mp.size() >= 5 && cntk == k){
                    int ub = upper_bound(pre.begin() , pre.end() , pre[j]) - pre.begin();
                    ans += (long long)(ub - j);
                    if(isVowel(word[i])){
                        mp[word[i]]--;
                        if(mp[word[i]] == 0){
                            mp.erase(word[i]);
                        }
                    }else{
                        cntk--;
                    }
                    i++;
                }
                j++;
            }
            return ans;
        }
    };