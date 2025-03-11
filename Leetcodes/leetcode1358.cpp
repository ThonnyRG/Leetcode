class Solution{
    public:
        int numberOfStrings(string s){
            int n = s.size();
            int count = 0, l = 0;
            vector<int>lastSeen = {-1,-1,-1};
            for (int i = 0; i < n; i++)
            {
                lastSeen[s[r]-'a'] = r;
                int mini = min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
                count += 1+mini;
            }
            return count;
        }

}