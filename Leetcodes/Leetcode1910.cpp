class Solution {
    public:
        string removeOccurrences(string s, string part) {
            while(s.find(part)!=-1){
                int id=s.find(part);
                s.erase(s.begin()+id,s.begin()+id+part.size());
            }
    
            return s;
        }
    };