class Solution {
    public:
        string clearDigits(string s) {
            bool p=1;
            while(p){
                p=0;
                for(int i=0;i<s.size();i++){
                    if(isdigit(s[i])){
                        p=1;
    
                        if(i)
                            s.erase(s.begin()+i-1,s.begin()+i+1);
                        else
                            s.erase(s.begin()+i,s.begin()+i+1);
                    break;
                    }
                }
            
            }
    
            return s;
        }
    };